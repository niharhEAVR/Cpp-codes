## 🔹 1. Destructor Basics

A **destructor** is a special function that cleans up when an object goes out of scope or is deleted.

Syntax:

```cpp
~ClassName();
```

---

## 🔹 2. Order of Destructor Calls in Inheritance

When an object of a derived class is destroyed:

1. **Derived class destructor runs first.**
2. Then the **base class destructor runs**.
3. If there’s a chain (like CivilEngineer → Engineer → Person), destructors are called in **reverse order of construction**.

👉 Think of it like **stack unwinding**:

* Constructors build from **base → derived**.
* Destructors destroy from **derived → base**.

---

## 🔹 3. Example With Your Hierarchy

```cpp
#include <iostream>
#include <string>

class Person {
public:
    Person() { std::cout << "Person constructor\n"; }
    virtual ~Person() { std::cout << "Person destructor\n"; } // virtual important
};

class Engineer : public Person {
public:
    Engineer() { std::cout << "Engineer constructor\n"; }
    ~Engineer() { std::cout << "Engineer destructor\n"; }
};

class CivilEngineer : public Engineer {
public:
    CivilEngineer() { std::cout << "CivilEngineer constructor\n"; }
    ~CivilEngineer() { std::cout << "CivilEngineer destructor\n"; }
};

int main() {
    CivilEngineer ce;
}
```

### ✅ Output:

```
Person constructor
Engineer constructor
CivilEngineer constructor
CivilEngineer destructor
Engineer destructor
Person destructor
```

---

## 🔹 4. Why Use **Virtual Destructors**?

If you delete a derived object through a **base class pointer**, you must make the base destructor `virtual`, otherwise only the base’s destructor runs (which causes resource leaks).

### Example:

```cpp
Person* p = new CivilEngineer();
delete p;   // What happens?
```

* If `~Person()` is **not virtual** → Only `Person` destructor runs ❌ (bad).
* If `~Person()` **is virtual** → `CivilEngineer` → `Engineer` → `Person` destructors run in order ✅ (correct cleanup).

---

## 🔹 5. Rule of Thumb

1. Always declare destructors `virtual` in **base classes meant for inheritance**.

   ```cpp
   virtual ~Base() = default;
   ```
2. Derived class destructors don’t need `virtual` explicitly (they automatically become virtual if the base has one).
3. Destructors always execute in **reverse construction order**.

---

✅ So in your case:

* `CivilEngineer` destructor runs first.
* Then `Engineer`.
* Then `Person`.

---

Would you like me to also show a **memory-leak example** when the base destructor is not virtual, so you see why it’s dangerous?

Perfect 👍 let’s look at a **real memory-leak example** when the base destructor is not virtual.

---

## 🔹 Example Without Virtual Destructor

```cpp
#include <iostream>

class Person {
public:
    Person() { std::cout << "Person constructor\n"; }
    ~Person() { std::cout << "Person destructor\n"; }  // ❌ Not virtual
};

class Engineer : public Person {
    int* m_data;  // simulate resource
public:
    Engineer() {
        m_data = new int[100];  // allocate heap memory
        std::cout << "Engineer constructor (allocated memory)\n";
    }
    ~Engineer() {
        delete[] m_data;  // cleanup
        std::cout << "Engineer destructor (freed memory)\n";
    }
};

int main() {
    Person* p = new Engineer();  // base pointer → derived object
    delete p; // ⚠️ Problem!
}
```

### ❌ Output:

```
Person constructor
Engineer constructor (allocated memory)
Person destructor
```

👉 What happened?

* Only `Person` destructor ran.
* `Engineer` destructor never ran.
* So `delete[] m_data` never executed → **memory leak!** 🚨

---

## 🔹 Example With Virtual Destructor

```cpp
#include <iostream>

class Person {
public:
    Person() { std::cout << "Person constructor\n"; }
    virtual ~Person() { std::cout << "Person destructor\n"; }  // ✅ Virtual now
};

class Engineer : public Person {
    int* m_data;
public:
    Engineer() {
        m_data = new int[100];
        std::cout << "Engineer constructor (allocated memory)\n";
    }
    ~Engineer() {
        delete[] m_data;
        std::cout << "Engineer destructor (freed memory)\n";
    }
};

int main() {
    Person* p = new Engineer();
    delete p;  // ✅ Safe now
}
```

### ✅ Output:

```
Person constructor
Engineer constructor (allocated memory)
Engineer destructor (freed memory)
Person destructor
```

👉 Now both destructors ran in the correct order.

* Memory allocated in `Engineer` is freed properly.
* Then base cleanup happens.
* No leaks 🚀

---

## 🔹 Golden Rule

* **Always make base class destructors `virtual`** if the class will be inherited and used polymorphically.
* Otherwise, you risk **undefined behavior or memory leaks** when deleting through a base pointer.