1. **Polymorphic objects**
2. **Object slicing**

Let's explain them from scratch before jumping to size calculations.

---

## 1️⃣ What is a Polymorphic Object?

👉 In C++, *polymorphism* means **“one interface, many forms”**.
That is, you can use a **base class pointer or reference** to call methods of different derived classes.

This only works if the base class has at least one **`virtual` function**.
When a class has a virtual function, we call it a **polymorphic class**, and its objects are **polymorphic objects**.

### Example:

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {   // virtual function
        cout << "Drawing Shape\n";
    }
};

class Circle : public Shape {
public:
    void draw() override {   // overrides Shape::draw
        cout << "Drawing Circle\n";
    }
};

int main() {
    Shape* s = new Circle();  // base pointer to derived object
    s->draw();  // Calls Circle::draw at runtime (polymorphism!)
    delete s;
}
```

👉 Here:

* `Shape` is **polymorphic** (because it has a `virtual` function).
* `Circle` objects are **polymorphic objects**.
* The magic: even though `s` is a `Shape*`, it actually calls `Circle::draw()`.

How does this work?
The compiler secretly adds a hidden pointer (`vptr`) inside every polymorphic object that points to a table (`vtable`) of virtual functions.

That’s why the **size of polymorphic objects** is bigger — because of that hidden pointer.

---

## 2️⃣ What is Object Slicing?

👉 *Slicing* happens when you assign/copy a **derived object** into a **base object by value**.
In that process, everything specific to the derived class gets **chopped off (sliced)**.

### Example:

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    int x = 1;
    virtual void draw() { cout << "Shape\n"; }
};

class Circle : public Shape {
public:
    int y = 2;
    void draw() override { cout << "Circle\n"; }
};

int main() {
    Circle c;     // has both x and y
    Shape s = c;  // ❌ slicing happens here

    cout << "s.x = " << s.x << endl; // works
    // cout << s.y;  // ❌ doesn't exist in Shape

    s.draw();  // prints "Shape" not "Circle"
}
```

👉 What happened?

* `Circle` has `x` (inherited) and `y` (extra).
* When assigned into a `Shape`, only the `Shape` part (`x`) is copied. The `y` and `Circle::draw()` info is lost.
* That’s why `s.draw()` prints `"Shape"` instead of `"Circle"`.

This is called **object slicing** because the “Circle part” got sliced off.

---

✅ So in simple words:

* **Polymorphic object** = an object of a class with `virtual` functions (it carries an extra hidden pointer for dynamic dispatch).
* **Object slicing** = when copying a derived object into a base object **by value**, the derived part is lost.

---
---
---


1. **Size of polymorphic objects** (objects with at least one `virtual` function)
2. **Object slicing** (what happens when you assign/copy a derived object into a base object)

---

## 1️⃣ Size of Polymorphic Objects

When you add a **`virtual` function** in a class, the compiler inserts a hidden pointer called the **vptr** (virtual pointer) inside the object.

* The `vptr` points to a **vtable** (virtual table) which stores addresses of the virtual functions.
* Because of this, **the size of a polymorphic object is at least the size of that pointer + data members**.

Example:

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    int x;  // 4 bytes
    virtual void draw() {}
};

class Circle : public Shape {
public:
    int y;  // 4 bytes
    void draw() override {}
};

int main() {
    cout << "Size of Shape: " << sizeof(Shape) << endl;
    cout << "Size of Circle: " << sizeof(Circle) << endl;
}
```

On a **64-bit system** (pointer = 8 bytes):

* `Shape`: `x (4) + padding (4) + vptr (8)` → **16 bytes**
* `Circle`: `x (4) + y (4) + vptr (8)` → **16 bytes**

⚠️ Exact sizes can vary (32-bit vs 64-bit, alignment rules, compiler).

👉 Key point: **A polymorphic object is always bigger than a non-polymorphic one** because of the hidden `vptr`.

---

## 2️⃣ Object Slicing

**Object slicing** happens when you copy/assign a derived object into a base object **by value**.

* Only the **base part** of the object is copied.
* The extra data from the derived class is “sliced off.”

Example:

```cpp
class Shape {
public:
    int x = 1;
    virtual void draw() { cout << "Shape\n"; }
};

class Circle : public Shape {
public:
    int y = 2;
    void draw() override { cout << "Circle\n"; }
};

int main() {
    Circle c;
    Shape s = c;   // ⚠️ Slicing happens here

    cout << "s.x = " << s.x << endl;
    // cout << "s.y = " << s.y; // ❌ Error: Shape has no y
    s.draw();   // "Shape", not "Circle"
}
```

👉 What happened?

* `s` is a pure `Shape` object, it doesn’t know about `y` or `Circle::draw()`.
* Even though you copied from a `Circle`, the derived info is lost.

---

## ✅ Summary

* **Polymorphic objects** have an extra hidden pointer (`vptr`), so they’re usually bigger than non-polymorphic objects.
* **Slicing** occurs when a derived object is copied into a base object **by value**, losing the derived part.
* To avoid slicing → use **references or pointers** (`Shape&`, `Shape*`) instead of copying.



---
---
---


# More explained way:

---

## 🔹 Case 1: Non-Polymorphic Class (no `virtual`)

```cpp
class Shape {
public:
    int x;   // 4 bytes
};
```

* On a **64-bit system** (where a pointer = 8 bytes):

  * Only `x` (4 bytes) exists.
  * Compiler may add **padding** (to align memory).
  * So `sizeof(Shape)` = **4 or 8 bytes** (depends on alignment rules).

---

## 🔹 Case 2: Polymorphic Class (has a `virtual` function)

```cpp
class Shape {
public:
    int x;               // 4 bytes
    virtual void draw(); // adds a hidden pointer (vptr)
};
```

* Because of `virtual`, the compiler adds a hidden **vptr (virtual pointer)** inside every object.
* On a 64-bit system, vptr = 8 bytes.
* Layout becomes:

  * `x` = 4 bytes
  * padding = 4 bytes (to align to 8)
  * vptr = 8 bytes
* Total = **16 bytes**

👉 So a polymorphic object is **larger** than a non-polymorphic one, because of the hidden vptr.

---

## 🔹 Case 3: Derived Polymorphic Class

```cpp
class Circle : public Shape {
public:
    int y;  // 4 bytes
    void draw() override;
};
```

* Inherits `x` (4 bytes) and vptr (8 bytes).
* Adds `y` (4 bytes).
* Likely layout:

  * `x` = 4 bytes
  * `y` = 4 bytes
  * vptr = 8 bytes
* Total = **16 bytes** again (on 64-bit).

If you add more members, size increases as usual, but the vptr adds **one hidden pointer per object**.

---

## 🔹 Object Slicing and Size

Now let’s see slicing in terms of size:

```cpp
Circle c;   // sizeof(Circle) = 16
Shape s = c; // slicing happens
```

* `s` is a plain `Shape` object → size = 16
* `c` is a `Circle` object → size = 16
* But when `c` is copied into `s`, only the **Shape part** of `c` is kept.
* The `y` member from `Circle` is discarded.

So slicing **doesn’t change sizeof** but it **changes what data is preserved**.

---

## ✅ Summary

* A **non-polymorphic object** only has its data members (+ padding).
* A **polymorphic object** has its data members + a hidden **vptr** (one pointer per object).
* On a **64-bit system**:

  * `Shape` with `int x` + virtual → **16 bytes**
  * `Circle` with `int x, int y` + virtual → **16 bytes**
* **Slicing** means: when copying derived → base by value, the extra derived members are lost.
