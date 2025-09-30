## **1. Polymorphic Functions in C++**

Polymorphism = *“many forms”*. In C++, a **polymorphic function** is one that can behave differently depending on the object or context.
There are **two main types of polymorphism**:

### (A) **Compile-time polymorphism** (also called *static polymorphism*)

* Achieved through **function overloading** and **operator overloading**.
* Decision is made at **compile time** (which function/operator to use).

**Example: Function Overloading**

```cpp
#include <iostream>
using namespace std;

class Print {
public:
    void show(int x) {
        cout << "Integer: " << x << endl;
    }
    void show(double y) {
        cout << "Double: " << y << endl;
    }
};

int main() {
    Print p;
    p.show(10);     // Calls show(int)
    p.show(3.14);   // Calls show(double)
}
```

---

### (B) **Runtime polymorphism** (also called *dynamic polymorphism*)

* Achieved through **virtual functions** and **inheritance**.
* The actual function that gets called depends on the **object type at runtime**, not just the pointer/reference type.

**Example: Virtual Function**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void speak() {   // virtual -> runtime polymorphism
        cout << "Base speaking..." << endl;
    }
};

class Derived : public Base {
public:
    void speak() override {
        cout << "Derived speaking..." << endl;
    }
};

int main() {
    Base* obj = new Derived();
    obj->speak();  // Calls Derived::speak() (runtime binding)
    delete obj;
}
```

👉 If `virtual` was not used, it would always call `Base::speak()` because of **compile-time binding**.

---

## **2. Access Specifiers in C++**

Access specifiers control **visibility** and **accessibility** of class members (variables, methods).

There are **three main access specifiers**:

### (A) **public**

* Accessible from **anywhere** (inside or outside the class).
* Used for interface functions.

```cpp
class Example {
public:
    int x;          // public
    void display() {
        cout << "x = " << x << endl;
    }
};
```

---

### (B) **private**

* Accessible **only within the class**.
* Not visible to derived classes (unless explicitly exposed).
* Used for encapsulation (data hiding).

```cpp
class Example {
private:
    int secret = 42;

public:
    int getSecret() {
        return secret;   // Accessible inside
    }
};
```

---

### (C) **protected**

* Accessible inside the class **and** by derived classes.
* Not accessible directly from outside.

```cpp
class Base {
protected:
    int value = 10;
};

class Derived : public Base {
public:
    void show() {
        cout << "Value = " << value << endl; // Accessible here
    }
};
```

---

## ✅ Connecting Both (Polymorphism + Access Specifiers)

* **Virtual functions (runtime polymorphism)** are usually declared as **public**, because they act as the interface.
* Sometimes you’ll see **protected virtual destructors**, so that only derived classes can delete through base pointers (to prevent misuse).
* Private functions can’t be overridden polymorphically (because they are not accessible in derived class).

---

🔹 In short:

* **Polymorphic functions** = same function behaves differently (compile-time or runtime).
* **Access specifiers** = control who can access class members (`public`, `private`, `protected`).

---
---
---


Let’s carefully analyze your code example with **polymorphism + access specifiers** together.

---

### **1. Setup in your code (assumptions)**

From what you showed:

* `Shape` is the **base class**.
* `Ellipse` is a **derived class**.
* `draw()` is a **virtual function** (for polymorphism).
* `func()` is some helper function, but its **access specifier differs** between `Shape` and `Ellipse`.

---

### **2. Key Observations from your code**

#### (A) **Base class pointer (shared_ptr<Shape>)**

```cpp
std::shared_ptr<Shape> shape0 = std::make_shared<Ellipse>(1, 5, "ellipse0");
shape0->draw();  // ✅ Works - polymorphism
shape0->func();  // ❌ Error: func is private in Shape
```

👉 Even though the actual object is `Ellipse`, the **type of pointer** is `Shape*`.
So the compiler checks **Shape’s access specifier**.

* `draw()` is `public` in `Shape` → accessible.
* `func()` is `private` in `Shape` → inaccessible.

That’s why the error.

---

#### (B) **Direct derived object**

```cpp
Ellipse ellipse1(1, 6, "ellipse1");
ellipse1.func();   // ✅ Works
ellipse1.draw();   // ❌ Error: draw() is private in Ellipse
```

👉 Here the type is **Ellipse**.
So the compiler checks **Ellipse’s access specifier**:

* `func()` is `public` in `Ellipse` → accessible.
* `draw()` is `private` in `Ellipse` → inaccessible.

---

#### (C) **Object slicing**

```cpp
Shape shape3 = Ellipse(2, 3, "ellipse3"); // slicing
shape3.draw();   // Shape::draw() called
shape3.func();   // ❌ Error: private in Shape
```

👉 Because of **slicing**, only the `Shape` part is kept.

* `draw()` from `Shape` is called (not virtual anymore, since object is `Shape`, not pointer/reference).
* `func()` is private in `Shape` → inaccessible.

---

### **3. What are the access specifiers saying here?**

Access specifiers are telling the compiler:

1. **Which version of the function (Shape vs Ellipse) is visible, depending on the object type.**

   * If you have a `Shape*`, access control comes from `Shape`.
   * If you have an `Ellipse` object, access control comes from `Ellipse`.
   * If you slice into `Shape`, you lose polymorphism → only `Shape` rules apply.

2. **Encapsulation rules are enforced before polymorphism.**

   * Even if a function exists in the derived class, if the base says it’s private, a base pointer/reference cannot call it.
   * In other words:

     > *The compiler looks at the **static type** (the declared type of the variable/pointer) to decide access control.*

---

### **4. Visualizing Access Check Flow**

| **Object/Pointer Type** | **Actual Object** | **Which Access Rules Apply?**   |
| ----------------------- | ----------------- | ------------------------------- |
| `Shape*` (base pointer) | `Ellipse`         | **Shape’s** access specifiers   |
| `Ellipse` object        | `Ellipse`         | **Ellipse’s** access specifiers |
| `Shape` object (sliced) | `Ellipse → Shape` | **Shape’s** access specifiers   |

---

✅ So in your example:

* Base pointer → checks `Shape`.
* Derived object → checks `Ellipse`.
* Sliced object → checks `Shape`.

---
---
---


Because this is a **modern C++ (C++11 and later)** feature that often confuses beginners.
Let’s go step by step in a **very beginner-friendly way**.

---

# 🔹 `shared_ptr` in C++

### **What is it?**

* `shared_ptr` is a **smart pointer** in C++.
* A *smart pointer* is an **object that acts like a raw pointer**, but also **manages the memory automatically**.
* Specifically, `shared_ptr` keeps track of **how many smart pointers point to the same object**.
* When the last `shared_ptr` pointing to an object goes out of scope → the object is **deleted automatically**. ✅ No `delete` needed.

👉 This avoids memory leaks and dangling pointers.

---

### **Simple Example**

```cpp
#include <iostream>
#include <memory> // for smart pointers

using namespace std;

class Test {
public:
    Test() { cout << "Constructor called\n"; }
    ~Test() { cout << "Destructor called\n"; }
};

int main() {
    shared_ptr<Test> p1 = make_shared<Test>(); // creates Test object
    {
        shared_ptr<Test> p2 = p1; // now 2 shared_ptrs point to the same object
        cout << "Use count: " << p1.use_count() << endl; // prints 2
    } // p2 goes out of scope → use_count decreases
    cout << "Use count: " << p1.use_count() << endl; // prints 1
} // p1 goes out of scope → object automatically destroyed
```

**Output**

```
Constructor called
Use count: 2
Use count: 1
Destructor called
```

👉 Notice: No `delete` is written by us. Memory management is automatic.

---

# 🔹 `make_shared` in C++

### **What is it?**

* `make_shared<T>(...)` is a function that:

  1. Allocates memory for the object of type `T`.
  2. Creates a `shared_ptr<T>` that manages it.
* It’s the **preferred way** to create `shared_ptr` objects (instead of using `new`).

---

### **Without make_shared**

```cpp
shared_ptr<int> p1(new int(5));
```

### **With make_shared**

```cpp
auto p2 = make_shared<int>(5);
```

✅ Advantages of `make_shared`:

1. **Faster & safer** (allocates control block + object together in one memory allocation).
2. **Exception safe** (no risk of leaks if constructor throws).
3. **Cleaner code**.

---

# 🔹 Why it’s used in your example?

```cpp
std::shared_ptr<Shape> shape0 = std::make_shared<Ellipse>(1, 5, "ellipse0");
```

* `make_shared<Ellipse>(1,5,"ellipse0")` → creates an `Ellipse` object with those constructor arguments.
* Returns a `shared_ptr<Ellipse>`.
* That `shared_ptr<Ellipse>` is **upcasted** to `shared_ptr<Shape>` (because `Ellipse` is a `Shape`).
* When `shape0` goes out of scope, the `Ellipse` object is destroyed automatically.

👉 No need to manually `delete` the object. Safe memory handling.

---

# ✅ Summary

* **`shared_ptr`** = smart pointer that shares ownership of an object (automatic deletion when last reference goes away).
* **`make_shared`** = function to create an object + wrap it inside a `shared_ptr` safely and efficiently.
* They are part of **C++ Standard Library** `<memory>` header.

---

Do you want me to also compare **`unique_ptr` vs `shared_ptr`** (both are smart pointers but behave differently)? That will help you see why we specifically use `shared_ptr` in polymorphism examples like yours.