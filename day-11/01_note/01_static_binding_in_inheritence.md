### 🔹 Binding in C++

When you call a function on an object through a pointer or reference, the compiler has to decide **which function implementation to run**.

There are two types of binding:

1. **Static Binding (Early Binding / Compile-Time Binding)**

   * Function to call is decided **at compile time**.
   * Default in C++.
   * Happens when functions are **not declared `virtual`**.
   * Works based on the **type of the pointer/reference, not the actual object it points to**.

2. **Dynamic Binding (Late Binding / Run-Time Binding)**

   * Function to call is decided **at runtime**.
   * Happens when functions are declared as **`virtual`** in the base class.
   * Works based on the **actual object type**, not the pointer/reference type.

---

### 🔹 Example with Inheritance

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    void draw() {  // <-- NOT virtual
        cout << "Drawing Shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Shape* s = new Circle();  // Base pointer pointing to derived object
    s->draw();                // Which draw() is called?
    delete s;
}
```

👉 Output:

```
Drawing Shape
```

* Even though `s` points to a `Circle`, the function called is **`Shape::draw`**, because `draw()` is **statically bound**.
* The compiler only sees the type `Shape*` at compile time, so it binds to `Shape::draw`.

---

### 🔹 Making it Dynamic Binding

```cpp
class Shape {
public:
    virtual void draw() {   // virtual makes it dynamically bound
        cout << "Drawing Shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};
```

👉 Now the same code outputs:

```
Drawing Circle
```

Because `draw()` is **virtual**, the call is resolved at runtime (dynamic binding).

---

### ✅ In Short

* **Static binding** (default): decided at **compile-time**, based on **pointer/reference type**.
* **Dynamic binding**: decided at **runtime**, based on **object type**, only happens with `virtual` functions.



---
---
---

Your program will still **compile and run** without the `override` keyword — because `override` is just a **safety check**, not a requirement in C++.

---

### 🔹 Why it works without `override`

When you write:

```cpp
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing Shape\n";
    }
};

class Circle : public Shape {
public:
    void draw() {   // no "override" keyword
        std::cout << "Drawing Circle\n";
    }
};
```

* Since `Shape::draw()` is marked `virtual`,
* `Circle::draw()` automatically **overrides** it (because it has the same name and signature).
* So at runtime, if you call `shape_ptr->draw();` where `shape_ptr` points to a `Circle`, you’ll get **"Drawing Circle"**.

The compiler understands the override even if you don’t write `override`.

---

### 🔹 What does `override` actually do?

It’s a **keyword introduced in C++11** that helps catch mistakes.

Example:

```cpp
class Shape {
public:
    virtual void draw(int x) { }  // notice: takes an int
};

class Circle : public Shape {
public:
    void draw() override { }  // ❌ Compiler Error
};
```

Here:

* Without `override`, this compiles, but it **doesn’t override** `Shape::draw(int)` — it just creates a new unrelated method `Circle::draw()`.
* With `override`, the compiler **forces a check**: "Are you really overriding a virtual method from the base class?" If not, it throws an error.

---

### ✅ Bottom line

* Your program works fine without `override`.
* But using `override` is considered **best practice** in modern C++ (C++11+) because it prevents subtle bugs.
