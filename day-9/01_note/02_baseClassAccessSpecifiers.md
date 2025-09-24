# 🔹 Base Class Access Specifiers

When you inherit a class in C++, you can specify one of three access modes:

```cpp
class Derived : public Base { ... };   // Public inheritance
class Derived : protected Base { ... }; // Protected inheritance
class Derived : private Base { ... };   // Private inheritance
```

The keyword after the colon (`public`, `protected`, `private`) is called the **base class access specifier**.

---

# 🔹 Effect of Base Class Access Specifiers

They control **how the base class members are inherited** into the derived class.

| Base member in `Base` | Public inheritance | Protected inheritance | Private inheritance |
| --------------------- | ------------------ | --------------------- | ------------------- |
| `public`              | stays `public`     | becomes `protected`   | becomes `private`   |
| `protected`           | stays `protected`  | stays `protected`     | becomes `private`   |
| `private`             | not inherited      | not inherited         | not inherited       |

---

# 🔹 Explanation

### 1. **Public Inheritance**

```cpp
class Derived : public Base {};
```

* “is-a” relationship.
* Public and protected members of `Base` keep the same access level.
* This is the **most common type of inheritance**.
* Example: `Dog` is a `public` `Animal`.

---

### 2. **Protected Inheritance**

```cpp
class Derived : protected Base {};
```

* Public and protected members of `Base` become **protected** in `Derived`.
* Outside code **cannot use base’s public members directly** anymore.
* Mostly used in framework/library design, rarely in normal OOP.

---

### 3. **Private Inheritance**

```cpp
class Derived : private Base {};
```

* Public and protected members of `Base` become **private** in `Derived`.
* Outside code has no direct access to base members via derived objects.
* Essentially “implemented in terms of,” not really “is-a.”
* Example: A `Car` might `private` inherit from an `Engine` (a car *has* an engine, but it’s not an engine).

---

# 🔹 Example Code

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int pub = 1;
protected:
    int prot = 2;
private:
    int priv = 3;
};

class DerivedPublic : public Base {
public:
    void show() {
        cout << pub << " " << prot << endl; // ✅ accessible
        // cout << priv; // ❌ private not inherited
    }
};

class DerivedProtected : protected Base {
public:
    void show() {
        cout << pub << " " << prot << endl; // ✅ accessible (but now protected)
    }
};

class DerivedPrivate : private Base {
public:
    void show() {
        cout << pub << " " << prot << endl; // ✅ accessible (but now private)
    }
};

int main() {
    DerivedPublic dp;
    dp.show();
    cout << dp.pub << endl;  // ✅ still public

    DerivedProtected dpr;
    dpr.show();
    // cout << dpr.pub; // ❌ not accessible (became protected)

    DerivedPrivate dpi;
    dpi.show();
    // cout << dpi.pub; // ❌ not accessible (became private)
}
```

---

# 🔹 Quick Analogy

Think of access specifiers like **security clearance levels**:

* **Public inheritance** → keep everyone’s clearance the same.
* **Protected inheritance** → downgrade everyone to “restricted.”
* **Private inheritance** → lock everything down, only the derived class itself can use it.
