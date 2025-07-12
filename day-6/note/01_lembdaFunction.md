## 🔹 What is a Lambda Function in C++?

A **lambda function** is an **unnamed, inline function** defined right inside your code, typically used where you would otherwise use a short regular function — especially in places like:

* `std::sort()`
* `std::for_each()`
* `std::transform()`
* Custom callback logic

---

## 🧠 Syntax of Lambda in C++

```cpp
[capture_clause] (parameter_list) -> return_type {
    function_body
};
```

Only the **capture clause** is required. Others are optional depending on what you're doing.

---

### ✅ Simple Example

```cpp
#include <iostream>

int main() {
    auto sayHello = []() {
        std::cout << "Hello from lambda!\n";
    };

    sayHello();  // Output: Hello from lambda!
}
```

---

## 🔍 Lambda Components Explained

| Part             | Purpose                                                                            |
| ---------------- | ---------------------------------------------------------------------------------- |
| `[ ]`            | **Capture clause** — allows the lambda to use variables from the surrounding scope |
| `( )`            | **Parameter list** — like any function                                             |
| `-> return_type` | (Optional) Explicit return type                                                    |
| `{ }`            | Function body                                                                      |

---

## 📦 Capturing Variables

Let’s say we have an outer variable:

```cpp
int a = 10;
```

We can **capture** it inside the lambda:

### 1. Capture by Value (`[=]` or `[a]`)

```cpp
auto lambda = [a]() {
    std::cout << a << "\n"; // copies 'a'
};
```

> 🔒 Captured **by value**, changes inside lambda won’t affect original `a`.

---

### 2. Capture by Reference (`[&]` or `[&a]`)

```cpp
auto lambda = [&a]() {
    a = a + 5;
};
```

> ✍ Captured **by reference**, so changes affect original variable.

---

### 3. Default capture modes

```cpp
[=]  // capture everything by value  
[&]  // capture everything by reference
```

---

### 4. Mixed capture

```cpp
[a, &b] // 'a' by value, 'b' by reference
```

---

## ✨ Lambda with Parameters and Return Type

```cpp
auto add = [](int x, int y) -> int {
    return x + y;
};

std::cout << add(3, 4);  // 7
```

Note: C++14 and newer can **deduce return type**, so this works too:

```cpp
auto add = [](int x, int y) {
    return x + y;
};
```

---

## 🛠 Practical Example — `std::sort` with Lambda

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {4, 1, 3, 9, 7};

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b; // descending order
    });

    for (int n : nums)
        std::cout << n << " ";
}
```

> Lambda is passed as a custom comparator function.

---

## ⚠️ Lambda Lifetimes and `mutable`

By default, value-captured variables **cannot be modified inside** a lambda.

```cpp
int x = 5;

auto lam = [x]() mutable {
    x += 10;
    std::cout << x << "\n";
};

lam();     // prints 15
std::cout << x << "\n"; // still 5
```

> `mutable` allows modifying the **copied (local)** value.

---

## 🔥 Summary

| Feature          | Description                                                                                                   |
| ---------------- | ------------------------------------------------------------------------------------------------------------- |
| **Lambda**       | Anonymous function object                                                                                     |
| **Capture**      | Pull in outer variables (by value or reference)                                                               |
| **Use Cases**    | Sorting, filtering, event handling, STL algorithms                                                            |
| **Mutable**      | Allows modifying captured-by-value copies                                                                     |
| **C++ Versions** | C++11: basic lambdas, C++14: return type deduction, C++20: lambdas in `constexpr`, lambdas in templates, etc. |

---
---
---


### Let's explore **why lambda functions were introduced in C++**, and what **problems they solve** that normal (named) functions can't handle easily or elegantly.

---

## ✅ Short Answer:

Lambda functions are created to allow **inline, anonymous, and flexible** functions — especially useful when:

* You need a **short function** for a **short-lived task**
* You want to **pass behavior (logic)** into an algorithm or function
* You want to **capture variables from the current scope**
* Creating a named function would be **too verbose or overkill**

---

## 🤔 Problems with Normal Functions

### ⚠️ Problem 1: Can't Capture Local Variables (Closure)

Regular functions **cannot access local variables** from their surrounding scope unless they are passed explicitly.

```cpp
int multiplier = 2;

int multiply(int x) {
    // ❌ Cannot use 'multiplier' here unless passed as parameter
    return x * multiplier;
}
```

✅ But a lambda can **capture** `multiplier`:

```cpp
int multiplier = 2;
auto multiply = [multiplier](int x) {
    return x * multiplier;
};
```

---

### ⚠️ Problem 2: Boilerplate for Small Tasks

If you want to sort a vector in descending order using a normal function:

```cpp
bool compare(int a, int b) {
    return a > b;
}

std::sort(vec.begin(), vec.end(), compare);
```

> Too much for such a small task.

✅ With lambda:

```cpp
std::sort(vec.begin(), vec.end(), [](int a, int b) {
    return a > b;
});
```

> Cleaner, shorter, and **only visible where needed**.

---

### ⚠️ Problem 3: Hard to Write Functions Inline

Sometimes, you want to pass **a function as an argument**. Using named functions makes this hard to manage:

```cpp
void process(std::function<void(int)> func) {
    func(10);
}
```

If you use a named function:

```cpp
void myFunction(int x) {
    std::cout << x * x;
}

process(myFunction);
```

✅ But with lambda:

```cpp
process([](int x) {
    std::cout << x * x;
});
```

> One-liner, **inline definition**, and **no extra function in global scope**.

---

## 💡 Real-World Use Cases of Lambdas

| Use Case                          | Why Lambda?              |
| --------------------------------- | ------------------------ |
| `std::sort`, `std::find_if`, etc. | Easy inline comparators  |
| Event handling in GUI             | Capture UI state/context |
| Filtering, mapping collections    | Short, flexible logic    |
| Custom thread/task functions      | No global naming clutter |
| Functional programming patterns   | Cleaner and modern code  |

---

## 🔍 When to Prefer Normal Functions

| Use Case                       | Prefer Normal Function |
| ------------------------------ | ---------------------- |
| Reusable logic across program  | ✅ Yes                  |
| Very long function bodies      | ✅ Yes                  |
| You want to test it separately | ✅ Yes                  |

---

## ✨ Summary: Lambda vs Normal Function

| Feature                | Lambda          | Normal Function             |
| ---------------------- | --------------- | --------------------------- |
| **Anonymous**          | ✅ Yes           | ❌ No — needs a name         |
| **Inline**             | ✅ Yes           | ❌ No                        |
| **Capture Variables**  | ✅ Yes (closure) | ❌ No (must pass explicitly) |
| **Reusable**           | ❌ Not ideal     | ✅ Better                    |
| **Short/One-time Use** | ✅ Best use case | ❌ Overkill                  |
| **Verbose?**           | ❌ No            | ✅ Often verbose             |

---

### 🧠 Final Thoughts

Lambda functions don't replace regular functions — they **complement** them.

* Use **lambda functions** when you need **short**, **inline**, **context-aware** logic.
* Use **regular functions** when you need **reusable**, **complex**, or **long** logic.