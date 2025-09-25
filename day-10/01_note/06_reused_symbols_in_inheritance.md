## 🔹 1. What are “symbols” here?

In C++ context, a *symbol* just means a **name** that identifies something:

* Data members (`m_age`, `m_full_name`, etc.)
* Member functions (`printInfo()`, `work()`, etc.)
* Even typedefs, enums, constants.

So, **reused symbols in inheritance** = when a **derived class introduces a name (symbol)** that already exists in the base class.

---

## 🔹 2. Example: Data Member Name Reuse

```cpp
class Person {
public:
    int m_age{20};
};

class Engineer : public Person {
public:
    int m_age{40}; // ❌ same name as Person::m_age → reused symbol
};
```

Usage:

```cpp
Engineer e;
std::cout << e.m_age;       // 40 (derived hides base member)
std::cout << e.Person::m_age; // 20 (can still access explicitly)
```

👉 The derived member `m_age` **hides** the base member `m_age`.
This is called **name hiding**.

---

## 🔹 3. Example: Function Name Reuse

```cpp
class Person {
public:
    void print() {
        std::cout << "Person print()\n";
    }
};

class Engineer : public Person {
public:
    void print() {  // ❌ same name reused
        std::cout << "Engineer print()\n";
    }
};
```

Usage:

```cpp
Engineer e;
e.print();         // Engineer print()
e.Person::print(); // Person print()
```

👉 Again, the derived `print()` **hides** the base’s `print()`.

---

## 🔹 4. The Trickier Case: Overloading Hidden

If base has overloaded functions, reusing the same name in derived hides **all overloads** from the base.

```cpp
class Person {
public:
    void work(int x) { std::cout << "Person work(int)\n"; }
    void work(double y) { std::cout << "Person work(double)\n"; }
};

class Engineer : public Person {
public:
    void work(std::string task) { std::cout << "Engineer work(string)\n"; }
};
```

Usage:

```cpp
Engineer e;
e.work("bridge");   // Engineer work(string)
// e.work(5);       // ❌ ERROR: Person::work(int) hidden
```

👉 Even though `Person` had `work(int)` and `work(double)`, they are hidden because `Engineer` reintroduced `work`.

To fix this, you can **reuse symbols explicitly**:

```cpp
class Engineer : public Person {
public:
    using Person::work; // bring all Person::work overloads into scope
    void work(std::string task) { std::cout << "Engineer work(string)\n"; }
};
```

Now:

```cpp
Engineer e;
e.work(5);         // Person work(int)
e.work(5.5);       // Person work(double)
e.work("bridge");  // Engineer work(string)
```

✅ The `using` declaration makes **base class overloads visible again** in the derived scope.

---

## 🔹 5. So in short:

* **Reused symbols** = when base and derived both have members with the same name.
* By default, the **derived symbol hides the base symbol**.
* You can still access the base version with `Base::name`.
* If you want all overloads visible, use `using Base::name;`.

---

⚡ So, when your book/teacher says *“reused symbols in inheritance”*, they’re basically talking about **name hiding (shadowing) of members or functions** in the inheritance chain.
