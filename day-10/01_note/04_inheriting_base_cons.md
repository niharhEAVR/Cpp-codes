## 🔹 Normal Behavior Without “Inheriting Constructors”

In classical C++, constructors are **not inherited**.
That means if the base class has constructors, the derived class **doesn’t automatically get them** — you either:

1. Write your own constructors in the derived class, or
2. Call the base constructor explicitly inside the derived constructor’s initializer list.

Example:

```cpp
class Person {
public:
    Person(std::string name, int age) {
        std::cout << "Person(name, age) constructor\n";
    }
};

class Engineer : public Person {
public:
    // We must explicitly define a constructor and forward parameters
    Engineer(std::string name, int age)
        : Person(name, age) {
        std::cout << "Engineer constructor\n";
    }
};
```

---

## 🔹 C++11 Feature: **Inheriting Constructors**

C++11 introduced a shortcut:
You can “inherit” constructors from a base class into a derived class using:

```cpp
using Base::Base;
```

This tells the compiler:
👉 “Make the base class constructors available in the derived class too.”

---

## 🔹 Example With Your Concept

```cpp
class Person {
public:
    Person(std::string name, int age) {
        std::cout << "Person(name, age) constructor\n";
    }
};

class Engineer : public Person {
public:
    using Person::Person;  // inherit Person’s constructors

    // Engineer can still add its own members if needed
    Engineer(std::string name, int age, int contracts)
        : Person(name, age), m_contracts(contracts) {
        std::cout << "Engineer(name, age, contracts) constructor\n";
    }

private:
    int m_contracts{};
};
```

### Usage:

```cpp
int main() {
    Engineer e1("Alex", 30);       // calls Person(name, age) → via inheritance
    Engineer e2("Bob", 25, 10);    // calls Engineer(name, age, contracts)
}
```

### ✅ Output:

```
Person(name, age) constructor
Person(name, age) constructor
Engineer(name, age, contracts) constructor
```

---

## 🔹 Key Points

* **`using Base::Base;`** automatically pulls in the base class’s constructors.
* You don’t need to rewrite “forwarding constructors” in the derived class.
* If you add your own custom constructors in the derived class, they **coexist** with the inherited ones.
* Inheriting constructors can’t directly initialize new data members in the derived class — those still need defaults or separate constructors.
