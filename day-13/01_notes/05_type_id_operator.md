## 🔹 What is `typeid` in C++?

The **`typeid` operator** in C++ is used to get **type information** about an object or a type **at runtime**.
It returns a **reference to a `std::type_info` object** that describes the type.

This is part of **RTTI** (Run-Time Type Information) in C++.

---

### Syntax:

```cpp
#include <typeinfo>

typeid(expression)
typeid(type-name)
```

---

### Return type:

* A `const std::type_info&` object.

You can query it for the type’s name or compare it with other types.

---

## 🔹 Basic Example

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int x = 5;
    double y = 3.14;

    cout << typeid(x).name() << endl; // type name for int
    cout << typeid(y).name() << endl; // type name for double
}
```

**Possible Output** (depends on compiler):

```
i
d
```

Here:

* `i` = `int`
* `d` = `double`

⚠️ The `.name()` result is implementation-dependent (varies between compilers).

---

## 🔹 Using `typeid` with Polymorphism

`typeid` is very useful for **finding the actual type of an object at runtime**, especially in polymorphic situations.

Example:

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

int main() {
    Base* basePtr = new Derived;

    cout << typeid(*basePtr).name() << endl; // dynamic type check
    cout << typeid(basePtr).name() << endl;  // static type check

    delete basePtr;
}
```

### Output (example):

```
7Derived
P4Base
```

Explanation:

* `typeid(*basePtr)` → gets the **dynamic type** (`Derived`), because `Base` has a virtual function.
* `typeid(basePtr)` → gets the **static type** (`Base*`), because the pointer’s type is known at compile time.

---

## 🔹 Important Points

1. **Polymorphism matters**

   * If you want `typeid` to give the real runtime type, the type must be **polymorphic** (have at least one virtual function).

2. **Static type vs dynamic type**

   * `typeid(pointer)` → gives **static type** (type of the pointer itself).
   * `typeid(*pointer)` → gives **dynamic type** (type of the object it points to, if polymorphic).

3. **Comparison**

```cpp
if (typeid(a) == typeid(b)) {
    cout << "Same type" << endl;
}
```

4. **Caveat:** `.name()` output is not standardized — it’s compiler-specific (useful for debugging, not portable type checking).

---

## 🔹 Real Example: Polymorphism + typeid

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

class Animal {
public:
    virtual ~Animal() {}
};

class Dog : public Animal {};
class Cat : public Animal {};

int main() {
    Animal* a = new Dog;
    Animal* b = new Cat;

    if (typeid(*a) == typeid(*b)) {
        cout << "Same type" << endl;
    } else {
        cout << "Different type" << endl;
    }

    delete a;
    delete b;
}
```

**Output:**

```
Different type
```

Because `typeid(*a)` returns `Dog` and `typeid(*b)` returns `Cat`.

---

✅ **Summary:**
`typeid` is used for **runtime type inspection** and works best with **polymorphic classes**. It’s part of RTTI and is useful for type comparison and safe casting.

---
---
---

# 🔹 Overview of the Example

The example demonstrates **four main points about `typeid`**:

1. `typeid` with **fundamental types**
2. `typeid` with **polymorphic references**
3. `typeid` with **polymorphic pointers**
4. `typeid` with **non-polymorphic pointers/references**

It’s showing the difference between **static type** and **dynamic type**, which is the key concept in RTTI (Run-Time Type Information).

---

# 🔹 1. `typeid` with fundamental types

```cpp
std::cout << "typeid(int) : " << typeid(int).name() << std::endl;
if (typeid(22.2f) == typeid(float)) { ... }
```

* `typeid` can be used with **primitive types** like `int`, `float`.
* Comparison works normally (`22.2f` is of type `float`).
* ✅ This is just **static type checking**.

---

# 🔹 2. `typeid` with polymorphic references

```cpp
DynamicDerived dynamic_derived;
DynamicBase &base_ref = dynamic_derived;

std::cout << "Type of dynamic_derived : " << typeid(dynamic_derived).name() << std::endl;
std::cout << "Type of base_ref : " << typeid(base_ref).name() << std::endl;
```

* `DynamicBase` has a **virtual function** → polymorphic.
* `dynamic_derived` is obviously of type `DynamicDerived`.
* `base_ref` is a **reference to base**, but actually refers to a **derived object**.

✅ `typeid` resolves **dynamic type** for references to polymorphic objects:

* `typeid(dynamic_derived)` → `DynamicDerived`
* `typeid(base_ref)` → `DynamicDerived` (not `DynamicBase`)

> This shows that **`typeid` can detect the actual derived type at runtime if the class is polymorphic**.

---

# 🔹 3. `typeid` with polymorphic pointers

```cpp
DynamicBase *b_ptr = new DynamicDerived;
std::cout << "Type of b_ptr : " << typeid(b_ptr).name() << std::endl; // static type
std::cout << "Type of *b_ptr : " << typeid(*b_ptr).name() << std::endl; // dynamic type
```

* `b_ptr` is of type `DynamicBase*` → **static type**
* `*b_ptr` is the object it points to → **dereferenced**, so `typeid` gives **dynamic type** (because `DynamicBase` is polymorphic)

**Key point:**

> For pointers, you need to **dereference** them to see the dynamic type. Otherwise, you just see the pointer type.

---

# 🔹 4. `typeid` with non-polymorphic pointers/references

```cpp
StaticBase *b_ptr_s = new StaticDerived;
StaticBase &static_base_ref{staticderived};

std::cout << "Type of *b_ptr_s : " << typeid(*b_ptr_s).name() << std::endl;
std::cout << "Type of static_base_ref : " << typeid(static_base_ref).name() << std::endl;
```

* `StaticBase` **has no virtual functions**, so it’s **non-polymorphic**.
* Even though `b_ptr_s` points to a `StaticDerived`, `typeid(*b_ptr_s)` → **StaticBase**, not derived.
* Similarly for `static_base_ref`.

✅ Key point:

> If the base class is **non-polymorphic**, `typeid` always returns the **static type**, ignoring the actual derived type.

---

# 🔹 🔑 Summary of What This Example Is Trying to Say

1. `typeid` can tell the type of **fundamental types** (static type).
2. `typeid` **with references or dereferenced pointers** gives the **dynamic type** **only if the type is polymorphic**.
3. **For non-polymorphic types**, `typeid` only gives the **static type** (compile-time type).
4. **Dereferencing pointers is necessary** to see the dynamic type.

---

### 🔹 Visual Summary

| Scenario                                       | Base Class Type          | Polymorphic? | `typeid` result                                      |
| ---------------------------------------------- | ------------------------ | ------------ | ---------------------------------------------------- |
| Fundamental type                               | int / float              | N/A          | Exact type (static)                                  |
| Reference to Derived (polymorphic)             | DynamicBase              | Yes          | Derived type (dynamic)                               |
| Pointer to Derived (polymorphic)               | DynamicBase*             | Yes          | Static for pointer, Dynamic for dereferenced pointer |
| Reference/Pointer to Derived (non-polymorphic) | StaticBase / StaticBase* | No           | Base type (static)                                   |
