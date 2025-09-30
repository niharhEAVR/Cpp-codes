# 🔹 Virtual Function With Default Arguments

### 1. **Virtual function** refresher

* A **virtual function** is a function in the base class that can be **overridden** in derived classes.
* Call is resolved at **runtime** (dynamic dispatch).
* Example:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived show()" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->show();   // Derived show()
    delete ptr;
}
```

---

### 2. **Default arguments** refresher

* Default arguments are decided at **compile time**, based on the **static type** of the pointer/reference.
* Example:

```cpp
void hello(string name = "World") {
    cout << "Hello, " << name << endl;
}

int main() {
    hello();          // Hello, World
    hello("Harsh");   // Hello, Harsh
}
```

---

### 3. **Mixing both (important point)**

When you use a **virtual function with default arguments**, there’s a twist:

* **Which function executes** → decided at **runtime** (dynamic binding).
* **Which default argument is used** → decided at **compile time** (static binding).

👉 So function override is dynamic, but default arguments are static.

---

### 4. **Example**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show(int x = 10) {
        cout << "Base::show, x = " << x << endl;
    }
};

class Derived : public Base {
public:
    void show(int x = 20) override {
        cout << "Derived::show, x = " << x << endl;
    }
};

int main() {
    Base* bptr = new Derived();

    bptr->show();   // Which happens?
    delete bptr;
}
```

**Output**

```
Derived::show, x = 10
```

---

### 5. **Why this happens?**

* Function call dispatch: **runtime → Derived::show is chosen**.
* Default argument: **compile-time → looks at Base::show’s default (10)**.

So you get `Derived::show(10)`.

---

# ✅ Key Takeaways

1. **Virtual function call = runtime binding**.
2. **Default arguments = compile-time binding**.
3. If base and derived classes specify different defaults, the **caller’s static type decides the argument**, not the actual object.
4. That’s why it’s **best practice to avoid default arguments on virtual functions**, because it can cause confusion.



---
---
---




Now I can explain properly **why each result comes out exactly like this**.

---

## 🔹 Your Classes

### **Base**

```cpp
virtual double add(double a = 5, double b = 5) const
{
    std::cout << "Base::add() called" << std::endl;
    return (a + b + 1);   // default args → 5,5 → result 11
}
```

### **Derived**

```cpp
virtual double add(double a = 10, double b = 10) const override
{
    std::cout << "Derived::add() called" << std::endl;
    return (a + b + 2);   // default args → 10,10 → result 22
}
```

⚠️ Key Point:

* **Virtual function** → resolved at **runtime** (dynamic dispatch).
* **Default arguments** → resolved at **compile time** (static type of variable/pointer/reference).

---

## 🔹 Walkthrough of `main()`

---

### **1. Base pointer → Derived object**

```cpp
Base *base_ptr1 = new Derived;
double result = base_ptr1->add();
```

* **Step 1 (function dispatch)**: `add()` is virtual → at runtime, the `Derived` version is called.
  ✅ So `Derived::add()` executes.
* **Step 2 (default args)**: Compiler looks at static type (`Base*`).
  Default args from `Base`: `(a=5, b=5)`.
* So actually it runs:

  ```cpp
  Derived::add(5, 5) → (5+5+2) = 12
  ```
* Output:

  ```
  Derived::add() called
  Result (base ptr) : 12
  ```

---

### **2. Base reference → Derived object**

```cpp
Derived derived1;
Base &base_ref1 = derived1;
result = base_ref1.add();
```

* Function dispatch → Derived::add (runtime).
* Default args → from `Base` (because type is `Base&`).
* Runs:

  ```cpp
  Derived::add(5, 5) → 12
  ```
* Output:

  ```
  Derived::add() called
  Result (base ref) : 12
  ```

---

### **3. Raw Base object**

```cpp
Base base3;
result = base3.add();
```

* Object is literally `Base`.
* No polymorphism, so it calls `Base::add()`.
* Default args → `5,5`.
* Runs:

  ```cpp
  Base::add(5, 5) → (5+5+1) = 11
  ```
* Output:

  ```
  Base::add() called
  raw result : 11
  ```

---

### **4. Direct Derived object**

```cpp
Derived derived2;
result = derived2.add();
```

* Object is literally `Derived`.
* No base pointer/reference, so compiler uses **Derived**’s default args.
* Runs:

  ```cpp
  Derived::add(10, 10) → (10+10+2) = 22
  ```
* Output:

  ```
  Derived::add() called
  Result (Direct object) : 22
  ```

---

### **5. Slicing**

```cpp
Base base1 = derived2;   // slicing
result = base1.add();
```

* `derived2` is a `Derived`, but assigning to `Base` **slices off the Derived part**.
* So now `base1` is just a `Base` object.
* No polymorphism → `Base::add()` is called.
* Default args → `5,5`.
* Runs:

  ```cpp
  Base::add(5, 5) → 11
  ```
* Output:

  ```
  Base::add() called
  Result (Raw objects assignment) : 11
  ```

---

## 🔹 Final Output Summary

```
Derived::add() called
Result (base ptr) : 12
---------------------
Derived::add() called
Result (base ref) : 12
---------------------
Base::add() called
raw result : 11
---------------------
Derived::add() called
Result (Direct object) : 22
---------------------
Base::add() called
Result (Raw objects assignment) : 11
```

---

## ✅ Big Takeaways

1. **Virtual function dispatch** is **runtime** → decides *which body* (`Base::add` or `Derived::add`) runs.
2. **Default arguments** are **compile-time** → come from the **static type** (pointer/ref/object type).

   * Base pointer/ref → Base’s defaults.
   * Derived object → Derived’s defaults.
3. **Slicing** destroys polymorphism → Derived part is cut off, only Base remains.
