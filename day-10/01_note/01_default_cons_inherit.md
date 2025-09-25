## 🔹 1. What is a *default constructor*?

In C++, a **default constructor** is a constructor that can be called without any arguments.

* Either explicitly defined by you:

```cpp
class A {
public:
    A() {   // default constructor
        std::cout << "A's default constructor\n";
    }
};
```

* Or implicitly provided by the compiler if you don’t define any constructor.

---

## 🔹 2. Inheritance and Constructors

When one class inherits from another, the **base class constructor runs first**, and then the derived class constructor runs.

👉 Rules:

1. If the **base class has a default constructor**, it will be called automatically.
2. If the **base class doesn’t have a default constructor**, then the derived class **must explicitly call one of the base class constructors** in its initializer list.

---

## 🔹 3. Example with Default Constructor

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() {  // default constructor
        cout << "Base default constructor called\n";
    }
};

class Derived : public Base {
public:
    Derived() {  // default constructor
        cout << "Derived default constructor called\n";
    }
};

int main() {
    Derived d;
    return 0;
}
```

### ✅ Output:

```
Base default constructor called
Derived default constructor called
```

* First the **Base class default constructor** is called automatically.
* Then the **Derived class default constructor** runs.

---

## 🔹 4. Case When Base Has No Default Constructor

If the base class has **only a parameterized constructor**, the derived class must explicitly call it:

```cpp
class Base {
public:
    Base(int x) {  // no default constructor
        cout << "Base parameterized constructor, x = " << x << endl;
    }
};

class Derived : public Base {
public:
    Derived() : Base(10) {  // explicitly call base constructor
        cout << "Derived default constructor\n";
    }
};

int main() {
    Derived d;
}
```

### ✅ Output:

```
Base parameterized constructor, x = 10
Derived default constructor
```

---

## 🔹 5. Summary

* **Default constructor** = constructor without arguments.
* With inheritance:

  * Base’s **default constructor is called automatically** before the derived’s constructor.
  * If no default constructor exists in Base, you must call another Base constructor explicitly in the Derived initializer list.
