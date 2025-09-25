## 🔹 1. What is a Copy Constructor?

A **copy constructor** is a special constructor that creates a new object as a copy of another object of the same class.

Signature:

```cpp
ClassName(const ClassName& other);
```

If you don’t define it, the compiler generates a **default copy constructor** which:

* Copies each member **shallowly** (bitwise copy for primitives, copy constructor for class-type members).
* Calls the **base class’s copy constructor** automatically in inheritance.

---

## 🔹 2. Why Custom Copy Constructor?

Sometimes the compiler-generated one is not enough, e.g.:

* When you have **private base members** (like your `m_address`) and need control.
* When you manage **dynamic resources** (pointers, heap memory).
* When you want to log / customize copy behavior.

---

## 🔹 3. How It Works in Your Example

Let’s extend your `Person → Engineer → CivilEngineer` hierarchy:

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Person {
protected:
    std::string m_full_name;
    int m_age{};
private:
    std::string m_address;

public:
    Person(std::string_view fullname, int age, std::string_view address)
        : m_full_name(fullname), m_age(age), m_address(address) {
        std::cout << "Person ctor\n";
    }

    // Custom copy constructor
    Person(const Person& other)
        : m_full_name(other.m_full_name), m_age(other.m_age), m_address(other.m_address) {
        std::cout << "Person copy ctor\n";
    }
};
```

```cpp
class Engineer : public Person {
protected:
    int m_contract_count{};

public:
    Engineer(std::string_view fullname, int age, std::string_view address, int contract_count)
        : Person(fullname, age, address), m_contract_count(contract_count) {
        std::cout << "Engineer ctor\n";
    }

    // Custom copy constructor
    Engineer(const Engineer& other)
        : Person(other), // call base copy constructor
          m_contract_count(other.m_contract_count) {
        std::cout << "Engineer copy ctor\n";
    }
};
```

```cpp
class CivilEngineer : public Engineer {
    std::string m_speciality;

public:
    CivilEngineer(std::string_view fullname, int age, std::string_view address,
                  int contract_count, std::string_view speciality)
        : Engineer(fullname, age, address, contract_count), m_speciality(speciality) {
        std::cout << "CivilEngineer ctor\n";
    }

    // Custom copy constructor
    CivilEngineer(const CivilEngineer& other)
        : Engineer(other), // call base copy constructor
          m_speciality(other.m_speciality) {
        std::cout << "CivilEngineer copy ctor\n";
    }
};
```

---

## 🔹 4. Usage

```cpp
int main() {
    CivilEngineer ce1("Alex", 30, "123 Street", 5, "Bridges");
    CivilEngineer ce2 = ce1; // copy constructor

    return 0;
}
```

### ✅ Output:

```
Person ctor
Engineer ctor
CivilEngineer ctor
Person copy ctor
Engineer copy ctor
CivilEngineer copy ctor
```

---

## 🔹 5. Key Takeaways

* In **inheritance**, the **base’s copy constructor is called automatically**, unless you explicitly specify another one.
* Best practice:

  ```cpp
  Derived(const Derived& other) : Base(other) { ... }
  ```

  This way, each class is responsible for copying its own members.
* This respects your earlier rule: **don’t directly touch private base members** — let the base handle them via its copy constructor.

---
---
---

## 🔹 When does a **copy constructor** get called?

The copy constructor is called when you **create a new object from an existing object** of the same type.

Examples where **copy ctor is called**:

```cpp
CivilEngineer ce1("Alex", 30, "123 Street", 5, "Bridges");
CivilEngineer ce2 = ce1;        // ✅ copy ctor
CivilEngineer ce3(ce1);         // ✅ copy ctor
CivilEngineer ce4{ce1};         // ✅ copy ctor
```

Each of these makes a **fresh object (ce2, ce3, ce4)** and initializes it with another object (`ce1`).
That’s why your log prints:

```
Person copy ctor
Engineer copy ctor
CivilEngineer copy ctor
```

---

## 🔹 When is **copy ctor NOT called**?

1. **Normal construction with parameters**:

```cpp
CivilEngineer ce("Alex", 30, "123 Street", 5, "Bridges");
```

Output:

```
Person ctor
Engineer ctor
CivilEngineer ctor
```

→ Because this is a **fresh object initialized directly** by constructor args, not copied.

---

2. **Assignment (not initialization)**:

```cpp
CivilEngineer ce1("Alex", 30, "123 Street", 5, "Bridges");
CivilEngineer ce2("Bob", 25, "456 Road", 3, "Tunnels");

ce2 = ce1;   // ❌ NOT copy ctor → this calls assignment operator
```

Here, `ce2` is already constructed, so the compiler calls the **copy assignment operator**, not the copy constructor.

---

## 🔹 Big Picture

* **Copy constructor** = “Create a new object from an existing one.”
* **Normal constructor** = “Create a new object from scratch with arguments.”
* **Copy assignment operator** = “Replace the contents of an existing object with another.”

---

✅ So yes — your line of thought is right:

> “just because we have created another fresh `eng2` and pasted all the properties of `eng1` to him”

That’s exactly why the **copy constructor** comes into play.
If `eng2` was *freshly written with its own parameters*, then the normal constructor would run instead.
