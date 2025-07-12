## 🔷 What is a Function Template in C++?

A **function template** lets you write a **generic function** — one that works with **any data type** — without rewriting the same logic multiple times for `int`, `float`, `double`, `string`, etc.

> ✅ It's like a **blueprint** for creating functions that work with **any type**.

---

### 🧾 Syntax:

```cpp
template <typename T>
T functionName(T arg1, T arg2) {
    // function body
}
```

* `template<...>` tells the compiler this is a **template**.
* `T` is a **template parameter** (can be any valid type when the function is used).
* You can use **more than one template type**: `template<typename T, typename U>`

---

## ✅ Basic Example: `max` Function

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

Now you can call:

```cpp
max(3, 7);          // T is int
max(3.14, 2.71);    // T is double
max('a', 'z');      // T is char
```

No need to write separate versions of `max` for each type.

---

## 🔍 Type Deduction (How does the compiler choose T?)

The compiler **automatically deduces** the type `T` based on the arguments you pass.

Example:

```cpp
max(5, 10);  // compiler sees both are int → T becomes int
```

### 💥 If Types Don’t Match?

```cpp
max(10, 12.5);  // int vs double → compiler error!
```

To fix it, use **explicit type specification**:

```cpp
max<double>(10, 12.5);  // both converted to double
```

---

## 🔧 Function Templates with Multiple Types

```cpp
template <typename T1, typename T2>
void display(T1 a, T2 b) {
    std::cout << "a: " << a << ", b: " << b << std::endl;
}
```

You can now call:

```cpp
display(5, "hello");
display(3.14, 42);
```

---

## 🎯 Why Use Function Templates?

| Feature     | Benefit                                                   |
| ----------- | --------------------------------------------------------- |
| DRY Code    | Write once, use for any type                              |
| Type Safety | Compiler checks types at compile time                     |
| Readability | No overloading clutter                                    |
| Performance | Code is **generated at compile time**, so no runtime cost |

---

## 🧠 Behind the Scenes: Template Instantiation

When you call a function template like:

```cpp
max(4, 7);
```

The compiler **generates** a concrete function like:

```cpp
int max(int a, int b) {
    return (a > b) ? a : b;
}
```

Each different type leads to a new version being generated.

---

## 🚨 Things to Know

### 1. **Templates must be fully defined in headers**

Because they are compiled **only when used**, the full definition must be visible to any file that uses them.

---

### 2. **Template Overloading**

You can overload templates like normal functions:

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int add(int a, int b) {
    return a + b + 100; // normal function, preferred for exact match
}
```

If both a **template and regular** function match, the **regular one is preferred**.

---

### 3. **Specialization**

Sometimes you want a different version for a specific type.

```cpp
template <typename T>
void print(T x) {
    std::cout << "Generic: " << x << std::endl;
}

// Specialization for char*
template <>
void print<char*>(char* x) {
    std::cout << "Special char*: " << x << std::endl;
}
```

---

### 4. **Constraints (C++20 Concepts)**

You can constrain template parameters using **concepts**:

```cpp
template <typename T>
requires std::is_integral_v<T>
T square(T x) {
    return x * x;
}
```

---

## ✅ Summary Table

| Concept                  | Description                               |
| ------------------------ | ----------------------------------------- |
| `template <typename T>`  | Declares a function template              |
| Type deduction           | Compiler figures out `T` from arguments   |
| Multiple template params | `template<typename T1, typename T2>`      |
| Overloading              | Works like normal functions               |
| Specialization           | Define custom versions for specific types |
| Constraints (C++20)      | Limit what types are allowed              |
| Compile-time expansion   | Each type generates a separate function   |

---

## 🚀 Final Example: Template + Generic Logic

```cpp
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

Now it works for `int`, `float`, `std::string`, etc.



---
---
---


## ✅ 1. **Templates Must Be Fully Defined in Headers**

### 🔍 What it means:

Template functions and classes are not compiled until they are **used** (i.e., when you pass a type to them). Because of this **lazy compilation**, the compiler **needs to see the full definition** of the template whenever it's used.

### ⚠️ Problem:

If you define a template function in a `.cpp` file and include only its declaration in a header file, other files **won’t be able to use** it.

---

### ✅ Correct way: define in header file (all together)

```cpp
// file: my_utils.h

#pragma once
#include <iostream>

template <typename T>
void print_value(T x) {
    std::cout << "Value: " << x << std::endl;
}
```

Then use in `main.cpp`:

```cpp
#include "my_utils.h"

int main() {
    print_value(5);        // T = int
    print_value(3.14);     // T = double
}
```

✅ Works perfectly — full template definition is visible.

---

### ❌ Wrong way: define template in `.cpp`

```cpp
// my_utils.h
template <typename T>
void print_value(T x); // only declaration

// my_utils.cpp
template <typename T>
void print_value(T x) {
    std::cout << x << std::endl;
}
```

```cpp
// main.cpp
#include "my_utils.h"

int main() {
    print_value(10);  // ❌ LINKER ERROR: undefined symbol
}
```

---

## ✅ 2. **Template Overloading**

You can have **multiple versions** of a function — some template, some non-template.

### 🔧 Example:

```cpp
#include <iostream>

template <typename T>
T add(T a, T b) {
    std::cout << "Template version\n";
    return a + b;
}

int add(int a, int b) {
    std::cout << "Non-template version\n";
    return a + b + 100;
}

int main() {
    std::cout << add(2, 3) << "\n";       // Uses non-template (exact match)
    std::cout << add(2.5, 3.5) << "\n";   // Uses template (no exact match)
}
```

### 🧠 Why?

* C++ always **prefers non-template functions** when both match exactly.
* So `add(int, int)` wins over `add<T>(T, T)` when both `T = int`.

---

## ✅ 3. **Template Specialization**

### 🔍 What is it?

Template specialization lets you **customize** the template’s behavior for **specific types**.

---

### 🔧 Example:

```cpp
#include <iostream>

// Generic template
template <typename T>
void print(T x) {
    std::cout << "Generic print: " << x << "\n";
}

// Specialization for char*
template <>
void print<char*>(char* x) {
    std::cout << "Special print for char*: " << x << "\n";
}

int main() {
    print(10);               // Uses generic
    print(3.14);             // Uses generic

    char* s = (char*)"Hello";
    print(s);                // Uses specialized version
}
```

### 🧠 Why?

Because printing `char*` as an integer pointer would be incorrect — so we specialize it to treat it like a string.

---

## 🧠 Summary Table

| Concept                       | Purpose                                                                                                                  |
| ----------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| **Full Definition in Header** | Templates must be **fully visible** when used — compiler needs the code to generate a version for the used type          |
| **Template Overloading**      | You can write both **template and non-template** functions with same name — non-template gets priority if match is exact |
| **Specialization**            | Write **custom version** of a template for a specific type                                                               |
