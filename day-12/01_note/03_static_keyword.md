## 🔹 1. What are static members?

* **Static data members** → shared by all objects of a class (one copy only).
* **Static member functions** → belong to the class itself, not to any particular object.

Example:

```cpp
class Test {
public:
    static int count;   // static data member
    static void hello() { cout << "Hello from Test\n"; }
};

int Test::count = 0;   // definition outside class

int main() {
    Test t1, t2;
    t1.count = 5;
    cout << t2.count << endl;  // 5 → shared
    Test::hello();             // call without object
}
```

---

## 🔹 2. Static members and polymorphism

Here’s the key point:
👉 **Static members do not participate in runtime polymorphism.**

Why?

* **Polymorphism requires virtual functions** → works only on *instance methods* tied to an object.
* **Static functions don’t belong to an object** → they are resolved at **compile time** (like normal functions), not at runtime.

---

## 🔹 3. Example with inheritance

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    static void sound() { cout << "Animal sound\n"; }
};

class Dog : public Animal {
public:
    static void sound() { cout << "Dog barks\n"; }
};

int main() {
    Animal* a = new Dog();

    a->sound();   // ❌ Calls Animal::sound(), not Dog::sound()
                  // because static functions are not virtual
    delete a;

    Dog::sound();     // Dog barks
    Animal::sound();  // Animal sound
}
```

👉 Even though `a` points to a `Dog`, it still calls `Animal::sound()` because `sound()` is **static**.
No polymorphism happens here.

---

## 🔹 4. Static data members in polymorphism

Static data members **can be shared across base and derived classes**, but again → not polymorphic.

```cpp
class Animal {
public:
    static int count;
};
int Animal::count = 0;

class Dog : public Animal {};

int main() {
    Dog d1;
    Animal a1;

    Dog::count++;
    Animal::count++;

    cout << Dog::count << endl;    // 2
    cout << Animal::count << endl; // 2 (same variable)
}
```

👉 Only **one copy exists** of `count`, regardless of polymorphism.

---

## 🔹 5. Summary

* **Static data members**: shared across objects; only one copy; not polymorphic.
* **Static functions**: belong to class, not object; resolved at compile-time; not virtual; cannot be overridden for polymorphism.
* **Polymorphism works only on instance (non-static) virtual functions**.

---

✅ **Therefore:**
Static members are useful for shared state or utility functions, but they **break polymorphism rules** — they’re always bound **statically**, never **dynamically**.
