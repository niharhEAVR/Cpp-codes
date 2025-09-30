# 🔹 What is `dynamic_cast` in C++?

`dynamic_cast` is a **runtime type casting operator** used mainly for **safe downcasting** (converting a base class pointer/reference to a derived class pointer/reference).

Unlike `static_cast` (which happens at compile time), `dynamic_cast` performs **runtime type checking** using **RTTI (Run-Time Type Information)**.
If the cast is invalid, it **fails safely** instead of causing undefined behavior.

---

## 🔹 Syntax

```cpp
dynamic_cast <new_type> (expression)
```

---

## 🔹 Where it is used?

1. **Polymorphic classes only**

   * The base class must have at least **one virtual function** (commonly a `virtual` destructor).
   * This is because `dynamic_cast` needs RTTI stored in the vtable.

2. **Safe downcasting** (Base → Derived).

   * It checks at runtime if the object is really of the derived type.

---

## 🔹 Example: Safe Downcasting

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {} // must be polymorphic
};

class Derived : public Base {
public:
    void show() { cout << "Derived class function\n"; }
};

int main() {
    Base* basePtr = new Derived();

    // Safe downcasting using dynamic_cast
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        derivedPtr->show(); // Works fine
    } else {
        cout << "Cast failed\n";
    }

    delete basePtr;
}
```

✅ Output:

```
Derived class function
```

Here `dynamic_cast` checked at runtime that `basePtr` actually pointed to a `Derived` object.

---

## 🔹 Example: Cast Failure

```cpp
class AnotherDerived : public Base {};

int main() {
    Base* basePtr = new AnotherDerived();

    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        derivedPtr->show();
    } else {
        cout << "Cast failed\n";  // Happens here
    }

    delete basePtr;
}
```

✅ Output:

```
Cast failed
```

⚠️ If we had used `static_cast` instead, it would compile but give **undefined behavior** (calling a function on an object of the wrong type).

---

## 🔹 `dynamic_cast` with References

When used with **references**, instead of returning `nullptr` on failure, it throws a `std::bad_cast` exception.

```cpp
try {
    Base& baseRef = *new AnotherDerived();
    Derived& derivedRef = dynamic_cast<Derived&>(baseRef); // will throw
} 
catch (bad_cast& e) {
    cout << "Bad cast: " << e.what() << endl;
}
```

---

## 🔹 Summary

* `dynamic_cast` = runtime-checked cast, requires polymorphism.
* ✅ Safe downcasting (Base → Derived).
* On failure:

  * With pointers → returns `nullptr`.
  * With references → throws `std::bad_cast`.
* Use it when you are unsure of the actual object type at runtime.



---
---
---


# 🔹 Key Idea of Your Program

You’re testing **runtime-safe casting** of an `Animal*` or `Animal&` into either a `Feline*` or `Dog*` using `dynamic_cast`.

This is exactly what `dynamic_cast` is meant for:

* ✅ Works only with **polymorphic classes** (so `Animal` must have at least one `virtual` function — usually a virtual destructor).
* ✅ Returns `nullptr` on failure if using pointers.
* ✅ Throws `std::bad_cast` on failure if using references.

---

# 🔹 Breaking Down Your Code

### 1. Casting a base pointer to derived pointer

```cpp
Animal *animal1 = new Feline("stripes", "feline1");

Feline *feline_ptr = dynamic_cast<Feline *>(animal1);

if (feline_ptr) {
    feline_ptr->do_some_feline_thingy();
} else {
    std::cout << "Couldn't do the transformation from Animal* to Dog*" << std::endl;
}
```

* `animal1` is of type `Animal*`, but it actually points to a `Feline` object.
* `dynamic_cast<Feline*>(animal1)` succeeds ✅, so `do_some_feline_thingy()` is called.
* If you had tried `dynamic_cast<Dog*>(animal1)`, it would fail and return `nullptr`.

---

### 2. Casting a base reference to derived pointer

```cpp
Feline feline2("stripes", "feline2");
Animal &animal_ref = feline2;

Dog *feline_ptr_1{dynamic_cast<Dog *>(&animal_ref)};
if (feline_ptr_1) {
    feline_ptr_1->do_some_dog_thingy();
} else {
    std::cout << "Couldn't cast to Dog reference,Sorry." << std::endl;
}
```

* `animal_ref` is an `Animal&`, but it actually refers to a `Feline`.
* You attempt to cast it to a `Dog*`.
* `dynamic_cast` checks RTTI at runtime → sees it’s not a `Dog` → returns `nullptr`.
* ✅ Correctly prints *"Couldn't cast to Dog reference, Sorry."*

---

### 3. Passing to functions

```cpp
do_something_with_animal_ptr(animal1);
do_something_with_animal_ref(animal_ref);
```

Both functions attempt a `dynamic_cast` inside.

* In `do_something_with_animal_ptr(animal1)`, `animal1` is `Feline*`, so cast succeeds → `do_some_feline_thingy()` runs.
* In `do_something_with_animal_ref(animal_ref)`, `animal_ref` is `Feline&`, so cast also succeeds.

---

### 4. Invalid cast example (commented)

```cpp
/*
int data{45};
int data_ptr = &data;

std::string data_str = dynamic_cast<std::string *>(data_ptr);
*/
```

⚠️ This won’t compile.
Why?

* `dynamic_cast` only works with **pointers/references to polymorphic class types**.
* `int` and `std::string` are unrelated types (no inheritance).
* You should use `static_cast` or `reinterpret_cast` for primitive → pointer conversions, but even then it’d be unsafe.

---

# 🔹 Typical Output (expected)

If `Animal` has a `virtual` destructor and `Feline` / `Dog` implement their methods:

```
Derived Feline function
-----------
Couldn't cast to Dog reference,Sorry.
---------------
In function taking base pointer...
Derived Feline function
In function taking base reference...
Derived Feline function
----------------
Done!
```

---

# 🔹 Key Takeaways from Your Code

1. `dynamic_cast` is **safe downcasting**.
2. Works only with **polymorphic base classes**.
3. With pointers → returns `nullptr` on failure.
4. With references → throws `std::bad_cast` if cast fails.
5. Never works between unrelated types (like `int` ↔ `std::string`).
