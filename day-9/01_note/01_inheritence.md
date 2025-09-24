### 🔷 What is **Inheritance** in C++?

**Inheritance** is one of the four fundamental **OOP (Object-Oriented Programming)** concepts in C++ (along with **Encapsulation, Abstraction, and Polymorphism**).
It allows a **class (called the derived class or child)** to **inherit properties and behaviors** (i.e., data members and member functions) from another **class (called the base class or parent)**.

---

### 🔶 Why Use Inheritance?

Inheritance promotes:

* **Code Reusability**: Avoids rewriting the same code in multiple classes.
* **Hierarchy Modeling**: Represents real-world relationships (e.g., Dog is a type of Animal).
* **Polymorphism**: Enables runtime behavior through virtual functions.

---

### 🔷 Basic Syntax

```cpp
class Base {
public:
    void display() {
        std::cout << "Base class display()" << std::endl;
    }
};

class Derived : public Base {
    // Inherits everything public and protected from Base
};
```

```cpp
int main() {
    Derived d;
    d.display(); // Inherited from Base
}
```

---

### 🔷 Types of Inheritance in C++

1. **Single Inheritance** – One base and one derived class
2. **Multilevel Inheritance** – Inheritance through multiple levels
3. **Multiple Inheritance** – One class inherits from more than one base class
4. **Hierarchical Inheritance** – One base class, many derived classes
5. **Hybrid Inheritance** – A combination of the above (may lead to Diamond Problem)

---

### 🔶 Access Specifiers in Inheritance

Inheritance type affects **access levels** in the derived class:

| Inheritance Type | Public Members Become | Protected Members Become | Private Members Become |
| ---------------- | --------------------- | ------------------------ | ---------------------- |
| `public`         | `public`              | `protected`              | Not Inherited          |
| `protected`      | `protected`           | `protected`              | Not Inherited          |
| `private`        | `private`             | `private`                | Not Inherited          |

```cpp
class Derived : public Base {};     // public inheritance
class Derived : protected Base {};  // protected inheritance
class Derived : private Base {};    // private inheritance
```

---

### 🔷 Real-World Analogy

Think of a **Base class** as a **blueprint** or **template**.

* **Base class**: `Vehicle` → has properties like speed, color.
* **Derived class**: `Car`, `Bike`, `Truck` → inherit from Vehicle but also have their own features.

---

### 🔷 Example: Single Inheritance

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Animal eats food" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog d;
    d.eat();  // Inherited from Animal
    d.bark(); // Own function
    return 0;
}
```

---

### 🔷 Constructor Behavior in Inheritance

* Base class constructor is always called **first**, then derived class constructor.
* Destructor is called in **reverse** order: Derived → Base.

```cpp
class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
};
```
