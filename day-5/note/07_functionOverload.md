### 🔄 What is **Function Overloading** in C++?

**Function overloading** in C++ means you can define **multiple functions with the same name**, **but with different parameter lists** (i.e., different types or numbers of parameters).

> It allows you to use the **same function name** to perform **different tasks** based on the input.

---

### 🧠 Why Function Overloading?

Because:

* It improves **readability** and **maintainability**.
* You don't need to remember different names for similar operations.
* The compiler knows which version to call based on the arguments passed.

---

## ✅ Rules of Function Overloading

Two or more functions can have the **same name** if they differ in:

1. **Number of parameters**, or
2. **Types of parameters**, or
3. **Order of parameters (if types are different)**

> ⚠️ You **cannot** overload just by **changing return type**.

---

### 🔧 Example 1: Different Number of Parameters

```cpp
#include <iostream>

void print() {
    std::cout << "No arguments\n";
}

void print(int a) {
    std::cout << "One int: " << a << "\n";
}

void print(int a, double b) {
    std::cout << "Int and double: " << a << ", " << b << "\n";
}

int main() {
    print();             // calls print()
    print(5);            // calls print(int)
    print(5, 3.14);      // calls print(int, double)
}
```

---

### 🔧 Example 2: Different Types of Parameters

```cpp
void show(int x) {
    std::cout << "Integer: " << x << "\n";
}

void show(std::string x) {
    std::cout << "String: " << x << "\n";
}
```

---

### ⚠️ Invalid Overload — Only Return Type Changed

```cpp
int getValue() {
    return 10;
}

// ❌ Error: cannot overload just by return type
double getValue() {
    return 3.14;
}
```

This will **not compile**, because:

> Return type is **not part of the function signature** used for overloading resolution.

---

### ✅ Behind the Scenes: How It Works

The compiler performs **name mangling** — it converts the overloaded function names internally into unique symbols depending on their parameters.

For example:

```cpp
void add(int, int);
void add(double, double);
```

Internally becomes something like:

```
add_int_int()
add_double_double()
```

So the **compiler knows exactly** which version to call.

---

### ✨ Summary

| Feature          | Description                            |
| ---------------- | -------------------------------------- |
| Name             | Same function name                     |
| Differentiation  | Number/type/order of parameters        |
| Return type only | ❌ Not allowed for overloading          |
| Benefit          | Cleaner, intuitive code                |
| Common use       | Constructors, printing, math ops, etc. |
