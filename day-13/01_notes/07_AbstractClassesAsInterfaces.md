## **1. Interface in Programming**

An **interface** is a design concept: it’s a **contract** that says:

> "Any class implementing this interface must provide certain functions."

Interfaces define *what* a class should do, but not *how* it should do it.

**Example in real life:**
Think of an interface like a **remote control standard**. Different manufacturers (Samsung, LG, Sony) can make remotes differently, but all must have the same basic buttons (power, volume, channel change).
The interface says:

* Power button must exist
* Volume control must exist
* Channel change must exist
  But doesn’t say how they work internally.

---

## **2. Abstract Class as an Interface in C++**

In C++, there is **no special “interface” keyword** like Java or C#.
Instead, we use **abstract classes with pure virtual functions** to act as interfaces.

### Syntax:

```cpp
class Interface {
public:
    virtual void function1() = 0;
    virtual void function2() = 0;

    virtual ~Interface() {} // Always add a virtual destructor
};
```

Here:

* `= 0` → means these are **pure virtual functions** (no implementation in the base class).
* The class is **abstract** → cannot create an object of it.
* Derived classes must implement all pure virtual functions.

This is exactly like an **interface**: it only defines a contract without implementation.

---

### Example:

```cpp
#include <iostream>
using namespace std;

class Drawable {
public:
    virtual void draw() = 0; // pure virtual function
    virtual ~Drawable() {}
};

class Circle : public Drawable {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public Drawable {
public:
    void draw() override {
        cout << "Drawing Square" << endl;
    }
};

int main() {
    Drawable* shapes[] = { new Circle(), new Square() };

    for (auto shape : shapes) {
        shape->draw(); // polymorphic call
    }

    for (auto shape : shapes) delete shape;
}
```

**Output:**

```
Drawing Circle
Drawing Square
```

---

## **3. Key Points — Why an Abstract Class is Used as Interface**

| Feature                       | Interface (abstract class) in C++ |
| ----------------------------- | --------------------------------- |
| No implementation             | Only pure virtual functions       |
| Purpose                       | Define a contract                 |
| Can have data members         | No (for a pure interface)         |
| Can have function definitions | Usually not                       |
| Must be inherited             | Yes                               |
| Can be used for polymorphism  | Yes                               |

---

## **4. Why Not Just Use a Normal Class?**

A normal class has both data and behavior.
An interface (abstract class with pure virtual functions) has **no implementation**, so it enforces **consistency** across different derived classes without dictating how the behavior is implemented.

---

## **5. Real-World Analogy**

Think of:

* Abstract class = a **blueprint**
* Interface = a **contract**

Example:

```cpp
class VehicleInterface {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};
```

Any class implementing `VehicleInterface` (Car, Bike, Truck) must provide `start()` and `stop()`.

---

### 🔹 Summary:

In C++, an **abstract class with only pure virtual functions** is effectively an **interface**.
It is used to **define behavior without implementation**, so different classes can implement that behavior in their own way.
