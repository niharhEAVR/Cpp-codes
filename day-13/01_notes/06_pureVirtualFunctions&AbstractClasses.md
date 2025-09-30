## 🔹 1. Pure Virtual Functions

A **pure virtual function** is a function in a base class that **must be overridden** by derived classes.
It has **no implementation** in the base class and is declared using `= 0`.

### Syntax:

```cpp
class Base {
public:
    virtual void show() = 0; // pure virtual function
};
```

Here:

* `virtual` means it supports **polymorphism**.
* `= 0` means it’s **pure virtual** → base class doesn’t implement it.

---

### Example:

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // pure virtual
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    // Shape s; // ❌ Error: cannot instantiate abstract class
    Circle c;
    c.draw();
}
```

**Output:**

```
Drawing Circle
```

---

## 🔹 2. Abstract Classes

A class containing **at least one pure virtual function** is called an **abstract class**.

### Key Points:

* You **cannot instantiate** an abstract class.
* Abstract classes are **used as base classes** for polymorphism.
* They force derived classes to implement certain methods.
* They are useful for defining an **interface**.

---

### Example:

```cpp
class Shape {
public:
    virtual void draw() = 0; // pure virtual
};

class Circle : public Shape {
public:
    void draw() override { cout << "Circle drawn" << endl; }
};

class Square : public Shape {
public:
    void draw() override { cout << "Square drawn" << endl; }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle();
    shapes[1] = new Square();

    for (int i = 0; i < 2; i++) {
        shapes[i]->draw(); // polymorphic call
    }
}
```

**Output:**

```
Circle drawn
Square drawn
```

---

## 🔹 3. Why Pure Virtual Functions & Abstract Classes Are Important

They allow:

* **Polymorphism**: Derived classes can be treated as base class objects.
* **Interfaces**: Enforce that all derived classes implement certain functions.
* **Code Reuse**: Common code can go into the base class while leaving implementation to derived classes.

---

### Real-World Analogy:

Think of `Shape` as an **interface** for all shapes.
Every shape (`Circle`, `Square`, etc.) must **implement the `draw()` function** in its own way.

---

## 🔹 4. Extra Facts

* An abstract class can have **normal member functions** and **member variables**.
* Pure virtual functions **can** have implementations, but the derived class must still override them.
* If a derived class does **not** override a pure virtual function → it remains abstract.

---

✅ Quick summary table:

| Term                  | Meaning                                              |
| --------------------- | ---------------------------------------------------- |
| Pure Virtual Function | Declared with `= 0` in base class, no implementation |
| Abstract Class        | Contains at least one pure virtual function          |
| Purpose               | Define a common interface for derived classes        |

---
---
---


If a class in C++ has **at least one pure virtual function**, it becomes an **abstract class**, and you **cannot instantiate it directly** (i.e., you cannot create an object of that class by its own name).

---

### Why?

Because a pure virtual function means **the class does not provide a full implementation**.
C++ forces you to **derive** and implement that function before creating an object.

---

### Example:

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // pure virtual
};

int main() {
    // Shape s; // ❌ Error: Cannot instantiate abstract class
    return 0;
}
```

Compiler Error:

```
error: cannot declare variable ‘s’ to be of abstract type ‘Shape’
```

---

### How to use it correctly:

You must **inherit** and **implement** the pure virtual function:

```cpp
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Circle c;   // ✅ OK, Circle implements draw()
    c.draw();
}
```

**Output:**

```
Drawing Circle
```

---

### Quick analogy:

Think of an abstract class as a **blueprint** — you cannot live in a blueprint house, you have to **build it first** by creating derived classes that implement all the missing details.
