## ✅ What is a Class in C++?

A **class** in C++ is like a **blueprint** for creating **objects**.

It groups **data** and **functions** together into one unit.

---

### 🔧 Think of a Class as a Template

A `class` defines:

* **What the object knows** → 📦 **Data members (variables)**
* **What the object can do** → ⚙️ **Member functions (methods)**

---

### 🧱 Example: Blueprint for a Car

```cpp
class Car {
public:
    std::string brand;
    int speed;

    void start() {
        std::cout << "Car started\n";
    }

    void accelerate() {
        speed += 10;
        std::cout << "Speed: " << speed << " km/h\n";
    }
};
```

Now this class `Car` is **not an object**, it’s a **blueprint**.

You use it to **create real objects**:

```cpp
int main() {
    Car myCar;           // create an object of type Car
    myCar.brand = "BMW";
    myCar.speed = 0;
    myCar.start();
    myCar.accelerate();  // Speed: 10
}
```

---

## 🧠 Why Do We Need Classes?

Because real-world things (and big programs) are **full of objects** with **data + behavior**.

### Imagine managing 100 cars:

Without classes:

* You’d need 100 separate variables and functions
* Code becomes messy and unstructured

With classes:

* You define it **once**
* Reuse it to create many objects
* It becomes easier to **organize, reuse, and maintain** code

---

## 🔄 Class vs Object

| Term     | Meaning                      |
| -------- | ---------------------------- |
| `class`  | Blueprint or template        |
| `object` | Real item created from class |

```cpp
class Dog {
public:
    void bark() {
        std::cout << "Woof!\n";
    }
};

int main() {
    Dog d1, d2;  // d1 and d2 are objects
    d1.bark();
    d2.bark();
}
```

---

## 🧰 Features of C++ Classes

| Feature           | Meaning                                                          |
| ----------------- | ---------------------------------------------------------------- |
| **Encapsulation** | Combine data + functions into one unit                           |
| **Abstraction**   | Hide unnecessary details (you don’t need to know how bark works) |
| **Inheritance**   | One class can inherit another’s features                         |
| **Polymorphism**  | One function behaves differently in different classes            |

We’ll get to these **OOP principles** soon.

---

## 🧱 Structure of a Class

```cpp
class ClassName {
private:
    // data members (usually hidden)
public:
    // functions you allow others to use
};
```

**Access specifiers**:

* `private` → accessible only inside the class
* `public` → accessible outside
* `protected` → used with inheritance

---

## ✅ Summary

| Thing            | Meaning                                                       |
| ---------------- | ------------------------------------------------------------- |
| Class            | Blueprint for objects                                         |
| Object           | Actual instance of class                                      |
| Why use classes? | Organize complex code, reuse logic, model real-world entities |
| How to use?      | Define class → create object → call functions                 |

---

## 🎯 Mini Exercise (Try It Yourself!)

```cpp
class Student {
public:
    std::string name;
    int marks;

    void show() {
        std::cout << "Name: " << name << ", Marks: " << marks << std::endl;
    }
};

int main() {
    Student s;
    s.name = "Rahul";
    s.marks = 89;
    s.show();  // Output: Name: Rahul, Marks: 89
}
```


---
---
---

## 🔷 What is a Constructor?

A **constructor** is a special function inside a class that is **automatically called when an object is created**.

### 🧠 Purpose:

> To **initialize** object member variables (set their values) when the object is created.

---

## 🛠 Types of Constructors in Your Code

You have **two constructors** in your `Cylinder` class:

```cpp
Cylinder() {
    base_radius = 2.0;
    height = 2.0;
}
```

✅ This is the **default constructor** (no parameters).
It's called when you write:

```cpp
Cylinder cylinder1;
```

---

```cpp
Cylinder(double rad_param, double height_param) {
    base_radius = rad_param;
    height = height_param;
}
```

✅ This is a **parameterized constructor**.
It’s called when you write:

```cpp
Cylinder cylinder2(6.9, 9.11);
```

---

## 🔍 Let's Walk Through Your Program

### 👇 Code

```cpp
Cylinder cylinder1;
```

* Calls `Cylinder()` → default constructor.
* Sets `base_radius = 2.0`, `height = 2.0`
* `volume()` is then called:

```cpp
volume = PI * 2.0 * 2.0 * 2.0 = ~25.13
```

You then modify:

```cpp
cylinder1.height = 3;
```

* Now `height = 3`
* Volume becomes:

```cpp
volume = PI * 2.0 * 2.0 * 3.0 = ~37.70
```

---

### Then this runs:

```cpp
Cylinder cylinder2(6.9, 9.11);
```

* Calls parameterized constructor.
* `base_radius = 6.9`, `height = 9.11`
* Volume becomes:

```cpp
volume = PI * 6.9 * 6.9 * 9.11 = ~1361.56
```

---

## 📌 Summary of Constructor Types

| Type                                    | Syntax                | When Called                        |
| --------------------------------------- | --------------------- | ---------------------------------- |
| **Default Constructor**                 | `Cylinder()`          | When no arguments are passed       |
| **Parameterized Constructor**           | `Cylinder(6.9, 9.11)` | When arguments are passed          |
| **Copy Constructor** *(not shown here)* | `Cylinder c2 = c1;`   | When copying one object to another |

---

## 🔒 Why Make `base_radius` Private?

You made this:

```cpp
private:
    double base_radius{};
```

That means you can’t do:

```cpp
cylinder1.base_radius = 4.5;  // ❌ ERROR
```

This is **encapsulation** — you control how important data is accessed/modified (only via constructors or methods).

---

## ✅ Visual Summary

```
      +-----------------------+
      |       Cylinder        |
      +-----------------------+
      | - base_radius (priv)  |
      | + height (public)     |
      +-----------------------+
      | + volume()            |
      | + Cylinder()          |
      | + Cylinder(double, d) |
      +-----------------------+

          Constructors ↓

    Cylinder c1;             // uses default constructor
    Cylinder c2(6.9, 9.11);  // uses parameterized constructor
```

---

## 🚀 Want to Make It Cleaner?

You can also write constructor initialization **this way** (recommended):

```cpp
Cylinder(double rad_param, double height_param)
    : base_radius(rad_param), height(height_param) {}
```

This is called a **member initializer list**, which is faster and cleaner.
