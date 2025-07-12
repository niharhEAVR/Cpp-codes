## 🔹 What is the **Capture Clause** in C++?

The **capture clause** is the part of a lambda function (the `[ ]` brackets) that tells the compiler **which variables from the surrounding scope** the lambda should "remember" and how (by value or by reference).

> Think of it as a way to **import** variables into the lambda’s body from the surrounding scope.

---

### ✅ Syntax Recap of Lambda Function

```cpp
[capture_clause] (parameter_list) -> return_type {
    // lambda body
};
```

Only the **`[capture_clause]`** is required. It controls how external variables are accessed inside the lambda.

---

## 🔍 Why Is It Needed?

Lambda functions are often used **inside other functions**, and you may want to use **local variables** of that outer function inside the lambda. But lambdas are like functions — so they **don’t automatically "see"** those variables unless you **capture** them.

---

## 🔧 Types of Captures in C++

Let’s suppose we have:

```cpp
int a = 10;
int b = 20;
```

Now, in your lambda:

### 1. **Capture by Value**: `[=]` or `[a]`

* Makes a **copy** of the variable.
* You **cannot modify** it unless you use `mutable`.

```cpp
auto lam = [=]() {
    std::cout << a << b;
};
```

## 🔹 `[=]` in a lambda's capture clause means:

> ✅ **"Capture all outer variables used in this lambda by **value**."**

That is, make a **copy** of each variable from the surrounding scope **if** it's used inside the lambda body.


### 🧪 Example:

```cpp
int a = 10;
int b = 20;

auto lam = [=]() {
    std::cout << a << " " << b << std::endl;
};
```

What happens here?

* The lambda function captures `a` and `b` by **value**.
* It makes a **copy** of both variables when the lambda is created.
* Inside the lambda, it uses the **copied versions** — not the original variables.

> ❗ You **cannot modify** `a` or `b` inside the lambda unless you use `mutable`.


### 🔥 Why is `[=]` useful?

It lets you **avoid writing each variable name**, like `[a, b, c]`, especially when you use many variables.

Instead of this:

```cpp
auto lam = [a, b, c, d]() { ... };
```

You can just write:

```cpp
auto lam = [=]() { ... };
```

As long as the lambda **uses** `a`, `b`, `c`, `d`, it will copy them automatically.


### ⚠️ Important Things About `[=]`

1. It does **not** mean "capture everything in the program" — only variables **used inside the lambda body**.
2. The captured variables are **read-only** unless you use the `mutable` keyword.


### 🚫 Example of Illegal Modification:

```cpp
int a = 10;
auto lam = [=]() {
    a += 5;  // ❌ error: can't modify captured-by-value variables
};
```

✅ But with `mutable`:

```cpp
auto lam = [=]() mutable {
    a += 5;  // ✅ ok — modifies the lambda's copy of `a`, not original `a`
};
```


### 🧠 Simple Analogy

Think of `[=]` as saying:

> "Give me a **photocopy** of any variable I touch."

While `[&]` says:

> "Give me **direct access** to the real variables."

---

Or to capture only `a`:

```cpp
auto lam = [a]() {
    std::cout << a;
};
```

### 2. **Capture by Reference**: `[&]` or `[&a]`

* Captures a **reference** to the variable.
* Any changes **affect the original**.

```cpp
auto lam = [&]() {
    b = b + 10;
};

```

## 🔹 Meaning of `&` in Lambda's Capture Clause

### ✅ It means: **Capture by Reference**

So:

```cpp
[&]      // capture ALL used outer variables by reference
[&a]     // capture only variable 'a' by reference
```

That means the lambda will **not copy** the variable — it will use the **original** variable from the outer scope, by **reference**.

---

## 💡 Visual Comparison

Let's say you have:

```cpp
int a = 10;
```

### 📌 `[=]` — capture by value

```cpp
auto lam = [=]() {
    std::cout << a;  // Uses a COPY of 'a'
};
```

* Lambda **copies** `a` into itself.
* You **cannot modify** it.
* Any changes to `a` inside the lambda **do not affect** the original `a`.

---

### 📌 `[&]` — capture by reference

```cpp
auto lam = [&]() {
    a += 5;  // Directly modifies the original 'a'
};
```

* Lambda **does not copy** `a`.
* It **accesses the real `a`** from outer scope.
* Changes inside the lambda **affect the original**.

---

## ✅ `[&a]` vs `[&]`

| Capture Clause | What It Does                                       |
| -------------- | -------------------------------------------------- |
| `[&a]`         | Captures **only** `a` by reference                 |
| `[&]`          | Captures **all used** outer variables by reference |
| `[a, &b]`      | Captures `a` by value, `b` by reference            |
| `[=, &b]`      | Default to value capture, but `b` by reference     |
| `[&, a]`       | Default to reference capture, but `a` by value     |

---

## 🧪 Example

```cpp
int a = 10;
int b = 20;

auto lam = [=]() {
    std::cout << a << " " << b;  // copies of a and b
};

auto lam2 = [&]() {
    b += 10;  // modifies outer b
};
```

---

## 🔥 Why use `&`?

Because sometimes:

* You need to **modify** outer variables.
* You want to **avoid making copies** of large objects.
* You want to see the **real memory address** of variables.

---

## ⚠️ Be Careful: Dangling References

```cpp
auto makeLambda() {
    int x = 42;
    return [&]() {
        std::cout << x;
    };
}

auto lam = makeLambda();
lam();  // ❌ undefined behavior! 'x' no longer exists!
```

Because `x` is destroyed when the function ends, and the lambda still holds a **reference** to it.

---

```cpp

auto lam2 = [&a]() {
    std::cout << a;
};
```

### 3. **Mixed Capture**

You can mix value and reference:

```cpp
auto lam = [a, &b]() {
    // 'a' is copied, 'b' is referenced
    std::cout << a + b;
};
```

---

### 4. **Default + Specific**

```cpp
auto lam = [=, &b]() { }; // all by value, except b by reference
auto lam = [&, a]() { };  // all by reference, except a by value
```

---

## 🧪 Example

```cpp
int x = 10, y = 20;

auto lambda = [x, &y]() {
    std::cout << "x: " << x << ", y: " << y << "\n";
    // x++; ❌ error (copied, can't modify unless mutable)
    y += 5;  // ✅ modifies original y
};

lambda();

std::cout << "Outside y: " << y; // y is changed
```

---

## 🧠 Special Capture Cases

### 🧷 `this` pointer capture

If you use a lambda inside a class and want to access `this`:

```cpp
[this]() { std::cout << this->member; }
```

Since C++17:

```cpp
[=, this]  // captures all by value + this
[&, this]  // all by reference + this
```

---

### 🧩 `mutable` keyword

By default, variables captured **by value** are read-only.

To make them modifiable **inside** the lambda:

```cpp
int x = 10;
auto lam = [x]() mutable {
    x += 5; // ✅ works because of mutable
    std::cout << x;
};
lam();
std::cout << x; // original x is still 10
```

---

## 📌 Summary Table

| Capture Clause | Meaning                                          |
| -------------- | ------------------------------------------------ |
| `[ ]`          | Captures nothing                                 |
| `[=]`          | Captures all external variables **by value**     |
| `[&]`          | Captures all external variables **by reference** |
| `[a]`          | Captures only `a` by value                       |
| `[&a]`         | Captures only `a` by reference                   |
| `[=, &b]`      | All by value, `b` by reference                   |
| `[&, a]`       | All by reference, `a` by value                   |
| `[this]`       | Captures `this` pointer in class methods         |

---

## 🔥 Final Notes

* Capture clause gives lambda **access to external variables**, unlike regular functions.
* Be careful with `[&]` — it can cause **dangling references** if you return the lambda.
* From **C++14 onward**, lambdas can be more powerful with generic types and initialized captures.
