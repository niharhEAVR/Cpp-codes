# ✅ What is "Scope" in C++?

> **Scope** refers to **where a variable or function is visible and can be used** in a program.

When you declare something (like a variable), it **only exists inside a certain region** — that's its **scope**.

---

## 🔹 Types of Scope in C++

We’ll go from **smallest scope** to **largest**:

---

### 1. 🔸 **Block Scope (Local Scope)**

Defined inside `{ }` — a block like a function, loop, `if`, etc.

```cpp
void show() {
    int x = 10; // x has block scope
    std::cout << x;
}
```

* `x` only exists inside the `show()` function.
* You **cannot access `x` outside** of it.

---

### 2. 🔸 **Function Scope (Label Scope)**

Labels used in `goto` have function scope.

```cpp
void myFunc() {
    goto here;

here:
    std::cout << "This is a label.\n";
}
```

* `here:` label can only be used inside `myFunc()`.

(Used rarely. Mostly for `goto`, not modern code style.)

---

### 3. 🔸 **Local Scope in Loops/Conditions**

```cpp
if (true) {
    int y = 20;
    std::cout << y;
}
// y is destroyed here
```

* `y` exists only inside the `if` block.

---

### 4. 🔸 **Function Parameter Scope**

```cpp
void add(int a, int b) {
    // a and b are local to this function
    std::cout << a + b;
}
```

* `a` and `b` only exist inside `add()`

---

### 5. 🔸 **Class Scope**

Variables and functions defined inside a class.

```cpp
class Car {
public:
    int speed;        // member variable
    void run() {
        std::cout << speed;
    }
};
```

* `speed` and `run()` are part of `Car`.
* They can be accessed only using objects of that class.

---

### 6. 🔸 **Global Scope**

Declared outside any function or class. Available **everywhere** (except shadowed).

```cpp
int globalVar = 100;

void show() {
    std::cout << globalVar;
}
```

* `globalVar` is visible to **all functions** after its declaration.

---

### 7. 🔸 **Namespace Scope**

Anything declared inside a `namespace` is scoped to it.

```cpp
namespace myspace {
    int value = 50;
}

int main() {
    std::cout << myspace::value;
}
```

* Use `namespace_name::item_name` to access.

---

### 8. 🔸 **File Scope (Static Variables/Functions)**

Using `static` outside functions means:

* That variable/function is only visible **within that file**.

```cpp
static int secret = 42;  // only accessible in this file
```

Useful in large projects to **hide internal stuff**.

---

### 9. 🔸 **Lifetime vs Scope**

* **Scope** = where variable is visible
* **Lifetime** = how long variable exists in memory

Example:

```cpp
int main() {
    {
        int x = 5;  // x is created here
    }              // x is destroyed here
}
```

---

## ⚠️ Shadowing

A **local variable with same name** as a global one will **hide (shadow)** the global one.

```cpp
int x = 100;

int main() {
    int x = 50; // local x shadows global x
    std::cout << x; // prints 50
}
```

Use `::x` to access global `x`.

---

## 🧠 Recap Table

| **Scope Type**  | **Where It's Declared**       | **Visible In**                  |
| --------------- | ----------------------------- | ------------------------------- |
| Block Scope     | Inside `{ }`                  | Only inside that block          |
| Function Scope  | Labels in a function          | Only in that function           |
| Parameter Scope | Function arguments            | Only inside that function       |
| Class Scope     | Inside class                  | Only inside class or via object |
| Global Scope    | Outside all functions/classes | Entire file (and beyond)        |
| Namespace Scope | Inside namespace              | Via `namespace::name`           |
| File Scope      | `static` variable/function    | Only in that source file        |

---

## ✅ Bonus: Examples You Can Run

### Example 1: Block Scope

```cpp
int main() {
    if (true) {
        int x = 10;
        std::cout << x; // ✅
    }
    // std::cout << x; ❌ error: x not declared here
}
```

---

### Example 2: Global and Shadowing

```cpp
int x = 100; // global

int main() {
    int x = 20;  // shadows global x
    std::cout << x << std::endl;   // prints 20
    std::cout << ::x << std::endl; // prints 100
}
```

---

### Example 3: Class Scope

```cpp
class Person {
public:
    int age;
    void show() {
        std::cout << age;
    }
};

int main() {
    Person p;
    p.age = 25;
    p.show(); // prints 25
}
```

---
---
---



## 🔷 Now Let's Cover These Remaining Parts:

---

### 1. 🔸 **Scope of Static Variables (Inside Functions)**

* **Keeps value even after function ends**
* But visible **only inside the function**

```cpp
void counter() {
    static int x = 0; // created only once
    x++;
    std::cout << x << std::endl;
}
```

```cpp
int main() {
    counter(); // prints 1
    counter(); // prints 2
    counter(); // prints 3
}
```

⏳ Lifetime = whole program
👀 Scope = inside the function

---

### 2. 🔸 **Unnamed (Anonymous) Namespaces**

```cpp
namespace {
    int hidden = 123;  // not accessible outside this file
}
```

This is similar to `static int hidden = 123;`
Useful to **limit access to only one file**.

---

### 3. 🔸 **Enum Scope**

#### ❌ Old-style `enum` — global names

```cpp
enum Color { RED, GREEN }; // RED and GREEN are in global scope
```

#### ✅ C++11 scoped enum (`enum class`) — names inside enum

```cpp
enum class Color { RED, GREEN };

Color c = Color::RED;  // ✅ safer, no name pollution
```

So `Color::RED` is scoped only inside `Color`.

---

### 4. 🔸 **Scopes in Lambdas**

In C++, lambdas can **capture variables** from outer scope:

```cpp
int x = 5;
auto f = [x]() { std::cout << x << std::endl; };
```

You control what is visible inside the lambda using:

| Syntax | Meaning                             |
| ------ | ----------------------------------- |
| `[x]`  | capture `x` by value                |
| `[&x]` | capture `x` by reference            |
| `[=]`  | capture all outer vars by value     |
| `[&]`  | capture all outer vars by reference |

---

### 5. 🔸 **Scope Resolution Operator `::`**

Used to access:

* **Global variable** if shadowed
* **Class members**
* **Namespace members**

```cpp
int x = 100;

int main() {
    int x = 20;
    std::cout << ::x;  // prints global x = 100
}
```

Also:

```cpp
namespace A {
    int value = 5;
}
std::cout << A::value;
```

---

### 6. 🔸 **Inheritance and Access Scopes (class-specific)**

Used in **OOP**, not variable visibility but **accessibility**:

```cpp
class Base {
protected:
    int a;
};

class Derived : public Base {
public:
    void show() {
        std::cout << a; // accessible here
    }
};
```

| Access Specifier | Visible In Derived Class? | Visible Outside? |
| ---------------- | ------------------------- | ---------------- |
| `public`         | ✅ Yes                     | ✅ Yes            |
| `protected`      | ✅ Yes                     | ❌ No             |
| `private`        | ❌ No                      | ❌ No             |

This is different from "scope" but often confused with it — it's about **access control**, not visibility by location.



---
---
---


## ✅ 1. **For Loop Variable Scope**

A variable declared inside a `for` loop header has **block scope** (only exists inside the loop).

```cpp
for (int i = 0; i < 5; ++i) {
    std::cout << i << " ";
}
// std::cout << i; ❌ Error: i doesn't exist here
```

> Even though `i` looks global inside the loop, it's **local to that block**.

---

## ✅ 2. **Try-Catch Variable Scope**

Any variable declared inside a `try` or `catch` block **exists only in that block**.

```cpp
try {
    int x = 5;
    throw x;
} catch (int e) {
    std::cout << e;
}
// std::cout << x; ❌ Error: x is out of scope
```

---

## ✅ 3. **Switch-Case Scope Pitfall**

Each `case` doesn’t have its own scope **unless** you add `{}`.

```cpp
int x = 1;
switch (x) {
    case 1:
        int a = 10;  // ✅ Okay if block is here
        std::cout << a;
        break;
    case 2:
        // int a = 20; ❌ Error if same name reused without block
        break;
}
```

To fix such cases, always use `{}` inside each case:

```cpp
case 1: {
    int a = 10;
    break;
}
```

---

## ✅ 4. **Inline Functions & Templates Scope Behavior**

When you put inline functions or templates in headers:

* Their **definition gets copied** to every `.cpp` file that includes the header.
* This is **allowed** only because all the copies must be **exactly identical**.

So technically they’re defined in **multiple scopes**, but it doesn't break ODR **because they’re identical**.

---

## ✅ 5. **Extern "C" and Scope (when mixing with C)**

If you’re calling a **C function** in a C++ program:

```cpp
extern "C" void c_func();
```

This tells the C++ compiler:

> “This function is defined in C code, so don’t mangle the name.”

It doesn't change *scope* directly, but **affects linking and symbol visibility**, which is a deeper scope-related topic in mixed C/C++ projects.

---

## ✅ 6. **Scopes in Nested Classes / Structs**

If a class is declared **inside another class**, the inner class is in the scope of the outer class.

```cpp
class Outer {
public:
    class Inner {
    public:
        void sayHi() {
            std::cout << "Hello from Inner\n";
        }
    };
};

int main() {
    Outer::Inner obj;
    obj.sayHi();
}
```

So `Inner` is **scoped to Outer** and must be accessed as `Outer::Inner`.

---

## ✅ 7. **Friend Functions and Scope**

A `friend` function **has access** to private/protected members, **but it is not in class scope**.

```cpp
class Test {
    int secret = 42;
    friend void show(Test t);
};

void show(Test t) {
    std::cout << t.secret;
}
```

* `show()` is **not** a member of `Test`.
* It's in **global scope**, but can still access private parts of `Test`.

---

## ✅ 8. **Scopes and Namespaces in Large Projects**

You can nest namespaces and scopes:

```cpp
namespace A {
    int x = 1;
    namespace B {
        int x = 2;
    }
}
```

Access using:

```cpp
A::x;      // 1
A::B::x;   // 2
```

---

## ✅ 9. **Scopes and Preprocessor Macros**

Preprocessor `#define` has **file-wide scope** from the point it's declared.

```cpp
#define PI 3.14

int main() {
    std::cout << PI;
}
```

It’s replaced **before compilation**, so it doesn’t obey normal C++ scope rules.
But it's good to remember: its **scope starts where it's defined and ends at EOF or #undef**.

---

## ✅ 10. **Scopes and Static Class Members**

Static class members are shared by all objects and live in global/static memory.

```cpp
class Demo {
public:
    static int count;
};

int Demo::count = 0;  // Defined outside the class

int main() {
    Demo::count = 5;
}
```

* `count` is **scoped inside the class**, but **defined globally**.

---

## 🧠 Final Thoughts

You're now covering **all levels** of scope in C++.
There are no more new types of scope left — just **variations** of what you already know.