Yes, ✅ **method/function overloading** **can** happen with **function templates**, including those that use **references**, just like with regular functions.

However, there are a few **important rules** and **gotchas** when combining **templates**, **references**, and **overloading**.

---

## 🔁 What is Function Overloading?

Function overloading means defining **multiple functions with the same name** but with **different parameter types or counts**, so the compiler chooses the right one based on the arguments.

```cpp
void print(int x) {}
void print(double y) {}  // ← Overloaded
```

---

## ✅ Function Template Overloading with Reference

You can overload **function templates**:

### 🔸 Example:

```cpp
#include <iostream>

template<typename T>
void show(T val) {
    std::cout << "Pass by value: " << val << "\n";
}

template<typename T>
void show(T& val) {
    std::cout << "Pass by reference: " << val << "\n";
}

int main() {
    int x = 10;
    show(x);  // Ambiguous ❌
}
```

### ❌ **Error: Ambiguity**

In the above case:

* Both templates could match `show(x)`

  * `T = int` → `show(int val)`
  * `T = int` → `show(int& val)`
* **Compiler can't decide** which one is better ⇒ **ambiguous**

---

## ✅ Overloading with const and non-const references

### Example:

```cpp
template<typename T>
void process(T& x) {
    std::cout << "Lvalue reference\n";
}

template<typename T>
void process(const T& x) {
    std::cout << "Const lvalue reference\n";
}

int main() {
    int a = 5;
    const int b = 6;
    process(a); // Calls T& → "Lvalue reference"
    process(b); // Calls const T& → "Const lvalue reference"
    process(10); // Calls const T& → "Const lvalue reference"
}
```

* `T&` accepts **non-const lvalues**
* `const T&` accepts **const lvalues and rvalues**

---

## ✅ Overloading Template vs Non-template

You can also overload a **template function with a regular (non-template) function**:

```cpp
void show(int x) {
    std::cout << "Non-template function\n";
}

template<typename T>
void show(T x) {
    std::cout << "Template function\n";
}

int main() {
    show(10); // Calls non-template (better match)
    show(3.14); // Calls template
}
```

The **compiler prefers non-template functions** if the match is equally good.

---

## ✅ Overloading with `T&`, `const T&`, `T&&` (Universal References)

```cpp
template<typename T>
void update(T& val) {
    std::cout << "Lvalue reference\n";
}

template<typename T>
void update(T&& val) {
    std::cout << "Rvalue (universal) reference\n";
}

int main() {
    int x = 10;
    update(x);     // Lvalue → calls T&
    update(20);    // Rvalue → calls T&&
}
```

This is called **perfect forwarding** or **universal reference** handling.

---

## 🔍 Summary Table

| Function Declaration      | Accepts                  | Used For                         |
| ------------------------- | ------------------------ | -------------------------------- |
| `void func(T val)`        | Copies everything        | Value semantics                  |
| `void func(T& val)`       | Lvalue only              | Modifiable input                 |
| `void func(const T& val)` | Const lvalues + rvalues  | Read-only access without copying |
| `void func(T&& val)`      | Rvalues (move semantics) | Efficient passing of temporaries |

---

## 🧠 Final Tip:

Overloading works **with references**, **with templates**, **between template and non-template functions**, and **with const-ness**—but be careful of **ambiguity** when multiple overloads can match the same call.
