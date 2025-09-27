## 1️⃣ Function Overloading

**Definition:**

> Defining **multiple functions with the same name** in the **same scope**, but **different parameter lists**.

* Compiler decides which one to call **at compile time** → **static binding**.
* Return type alone **cannot** distinguish overloads; parameters must differ.

### Example:

```cpp
#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};

int main() {
    Math m;
    cout << m.add(2, 3) << endl;       // calls int version
    cout << m.add(2.5, 3.5) << endl;   // calls double version
}
```

* `add(int,int)` and `add(double,double)` → **overloaded** functions.
* Chosen **at compile time**.

---

## 2️⃣ Function Overriding

**Definition:**

> A **derived class provides its own version** of a **base class’s virtual function**.

* Must have the **same name and signature** (const matters too).
* Compiler uses **dynamic dispatch** (runtime decision) → **polymorphism**.

### Example:

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() { cout << "Drawing Shape" << endl; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle" << endl; }
};

int main() {
    Shape* s = new Circle();
    s->draw();  // Calls Circle::draw() because of virtual function
    delete s;
}
```

* **draw() in Circle overrides draw() in Shape**.
* `override` keyword is optional but recommended.

---

## 3️⃣ Function Hiding

**Definition:**

> When a **derived class declares a function with the same name** as a base class function **but does not match signature exactly**, the base class function becomes **hidden**.

* This can happen even if the base function is **virtual**.
* Compiler will call the derived class version **if using a derived object**; base version is hidden from derived.

### Example:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void func(int x) { cout << "Base func(int)" << endl; }
};

class Derived : public Base {
public:
    void func(double x) { cout << "Derived func(double)" << endl; }
};

int main() {
    Derived d;
    // d.func(5); // ❌ Error! Base func(int) is hidden by Derived func(double)
    d.func(5.5);  // Calls Derived func(double)
}
```

* Even though `Base` has `func(int)`, it is **hidden** by `Derived`’s `func(double)`.
* To call base version:

```cpp
d.Base::func(5);  // Explicitly call base version
```

---

## 4️⃣ Quick Comparison

| Concept         | Where defined  | Same signature?       | Binding      | Notes               |
| --------------- | -------------- | --------------------- | ------------ | ------------------- |
| **Overloading** | Same class     | No (different params) | Compile-time | Static polymorphism |
| **Overriding**  | Base + Derived | Yes                   | Run-time     | Requires `virtual`  |
| **Hiding**      | Base + Derived | No (diff signature)   | Compile-time | Base version hidden |

---

💡 **Memory/Polymorphism perspective:**

* Overloading → no vtable, compiler chooses function at compile time.
* Overriding → vtable used for runtime polymorphism.
* Hiding → can cause surprises; always check signatures carefully.
