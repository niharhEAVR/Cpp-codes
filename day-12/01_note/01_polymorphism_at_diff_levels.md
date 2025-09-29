Polymorphism in programming (especially in **Object-Oriented Programming, OOP**) means **"many forms"** — the same entity (function, operator, object) behaves differently depending on the context.

It exists at **different levels**:

---

# 🔹 1. **Polymorphism at the Language Level**

This is built into the programming language itself.
Examples:

* **Operator Overloading** (same operator behaves differently for different data types)

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << 5 + 10 << endl;       // integer addition
    cout << 3.5 + 2.2 << endl;    // floating-point addition
    cout << string("Hi ") + "C++"; // string concatenation
}
```

Here, `+` is polymorphic → same symbol but different behavior depending on type.

---

# 🔹 2. **Polymorphism at the Function/Method Level**

Two kinds:

### (a) **Compile-Time Polymorphism (Static Binding / Early Binding)**

* Achieved via **function overloading** and **operator overloading**.
* Resolved at **compile-time**.

```cpp
#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Math m;
    cout << m.add(5, 3) << endl;       // calls int version
    cout << m.add(3.2, 4.8) << endl;   // calls double version
}
```

---

### (b) **Run-Time Polymorphism (Dynamic Binding / Late Binding)**

* Achieved via **virtual functions** (method overriding).
* Resolved at **runtime**.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {  // virtual function
        cout << "Some generic sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->sound();   // Bark!
    a2->sound();   // Meow!
}
```

Here, the **same function call (`sound()`) behaves differently** depending on the actual object type.

---

# 🔹 3. **Polymorphism at the Class Level**

This is when **derived classes specialize or override behavior** of a base class.

* Example: Inheritance + overriding.
* The **parent reference can point to child objects**, but the method executed depends on the actual object type.

(Same as above `Animal` → `Dog` / `Cat` example.)

---

# 🔹 4. **Polymorphism at the Object Level**

When the **same object** exhibits different behavior in different contexts.

Example:

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() { cout << "Drawing Shape\n"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle\n"; }
};

class Square : public Shape {
public:
    void draw() override { cout << "Drawing Square\n"; }
};

int main() {
    Shape* shape;

    shape = new Circle();
    shape->draw();   // behaves as Circle

    shape = new Square();
    shape->draw();   // behaves as Square
}
```

The **same pointer `shape` (object reference) changes behavior dynamically.**

---

# 🔹 5. **Polymorphism at the Application/Design Level**

This is a higher-level view: designing systems with polymorphism for **flexibility and scalability**.

* Example: A payment system:

```cpp
class Payment {
public:
    virtual void pay(int amount) = 0; // pure virtual
};

class CreditCard : public Payment {
public:
    void pay(int amount) override { cout << "Paid " << amount << " using Credit Card\n"; }
};

class UPI : public Payment {
public:
    void pay(int amount) override { cout << "Paid " << amount << " using UPI\n"; }
};

int main() {
    Payment* p = new CreditCard();
    p->pay(500);

    p = new UPI();
    p->pay(200);
}
```

Now, the system doesn’t care about **how payment is made**, only that a `Payment` object exists. This is **real-world polymorphism in software design**.

---

✅ **Summary Table**

| Level       | Example                            | Key Idea                          |
| ----------- | ---------------------------------- | --------------------------------- |
| Language    | `+` works on int, float, string    | Operator polymorphism             |
| Function    | Overloading / Overriding           | Same function name, different use |
| Class       | Base ↔ Derived relationship        | Method overriding                 |
| Object      | Same reference behaves differently | Runtime dynamic dispatch          |
| Application | Payment system, GUI widgets, etc.  | Abstract design flexibility       |
