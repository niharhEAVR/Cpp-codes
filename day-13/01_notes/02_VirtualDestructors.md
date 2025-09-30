## 🔹 What is a **Virtual Destructor** in C++?

In C++, a **destructor** is a special member function that is automatically called when an object goes out of scope or is explicitly deleted.

When you declare a destructor as **`virtual`** in a base class, it ensures that the **derived class destructor is also called** when you delete a derived object through a base class pointer.

### Syntax:

```cpp
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor\n";
    }
};
```

---

## 🔹 Why do we need a **Virtual Destructor**?

Consider this scenario:

### Case 1: Without virtual destructor

```cpp
class Base {
public:
    ~Base() { 
        std::cout << "Base destructor\n"; 
    }
};

class Derived : public Base {
public:
    ~Derived() { 
        std::cout << "Derived destructor\n"; 
    }
};

int main() {
    Base* obj = new Derived();  // Base pointer, Derived object
    delete obj;  // Only Base destructor is called!
}
```

**Output:**

```
Base destructor
```

⚠️ **Problem:** The `Derived` destructor never runs!
If `Derived` allocated some memory or resources (like heap memory, file handles, sockets), they won’t be released → leading to **memory leaks** or resource leaks.

---

### Case 2: With virtual destructor

```cpp
class Base {
public:
    virtual ~Base() { 
        std::cout << "Base destructor\n"; 
    }
};

class Derived : public Base {
public:
    ~Derived() { 
        std::cout << "Derived destructor\n"; 
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Calls Derived::~Derived() then Base::~Base()
}
```

**Output:**

```
Derived destructor
Base destructor
```

✅ Now both destructors run in the **correct order**:

* First the **derived class destructor**
* Then the **base class destructor**

---

## 🔹 When should you make a destructor virtual?

👉 You **must** make the destructor `virtual` in a **base class** if you intend to use it **polymorphically** (i.e., deleting derived objects through base pointers).

### Example:

* If a class will be **inherited** and used with **virtual functions**, make its destructor virtual.
* If a class will **never be inherited** (like utility classes, final classes), you don’t need a virtual destructor.

---

## ✅ Summary

* **Virtual destructor** = ensures derived destructor runs when deleting via base pointer.
* **Without virtual** → possible memory/resource leaks.
* **Rule of thumb**: If your class has any virtual functions, make the destructor virtual too.
