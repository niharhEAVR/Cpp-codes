In C++20 concepts, you **can use logical operators** to **combine or invert conditions** inside **concept definitions** and **`requires` clauses**.

---

## ✅ Logical Operators You Can Use

| Operator | Meaning | Example                          |    |                           |
| -------- | ------- | -------------------------------- | -- | ------------------------- |
| `&&`     | AND     | Both conditions must be true     |    |                           |
| \`       |         | \`                               | OR | At least one must be true |
| `!`      | NOT     | Invert the result of a condition |    |                           |

These work **both in concept definitions** and **directly in `requires` expressions.**

---

## 🔍 Example 1: Combining Concepts Using `&&` (AND)

```cpp
#include <iostream>
#include <concepts>
#include <type_traits>

template <typename T>
concept SmallIntegral = std::is_integral_v<T> && (sizeof(T) <= 4);

template <SmallIntegral T>
void print(T x) {
    std::cout << "Small integral: " << x << std::endl;
}
```

✅ Works for `int`, `short`, `char`
❌ Fails for `long long` or `double`

---

## 🔍 Example 2: Using `||` (OR) to Allow Either Floating Point or Integral

```cpp
template <typename T>
concept Arithmetic = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <Arithmetic T>
T square(T x) {
    return x * x;
}
```

✅ Works for `int`, `double`, `float`
❌ Fails for `std::string`, `bool*`, etc.

---

## 🔍 Example 3: Using `!` (NOT) to Exclude Types

```cpp
template <typename T>
concept NotPointer = !std::is_pointer_v<T>;

template <NotPointer T>
void display(T x) {
    std::cout << "Not a pointer: " << x << std::endl;
}
```

✅ Works for `int`, `double`, etc.
❌ Fails for `int*`, `char*`, etc.

---

## 🧪 Example 4: Inside a `requires` Clause with `&&` and `->`

```cpp
template <typename T>
concept AddAndMultiply = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
    { a * b } -> std::convertible_to<T>;
};
```

Same as:

```cpp
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};

template <typename T>
concept Multipliable = requires(T a, T b) {
    { a * b } -> std::convertible_to<T>;
};

template <typename T>
concept AddAndMultiply = Addable<T> && Multipliable<T>;
```

---

## 🔧 Practical Use in Templates

```cpp
template <typename T>
requires std::is_integral_v<T> || std::is_floating_point_v<T>
T add(T a, T b) {
    return a + b;
}
```

This means:

> Allow `add()` only if `T` is either integral **or** floating-point.

---

## ✅ Summary Table

| Operator | Use Case                    | Example                         |                                     |                           |   |                                  |
| -------- | --------------------------- | ------------------------------- | ----------------------------------- | ------------------------- | - | -------------------------------- |
| `&&`     | All conditions must be true | `Addable<T> && Multipliable<T>` |                                     |                           |   |                                  |
| \`       |                             | \`                              | At least one condition must be true | \`std::is\_integral\_v<T> |   | std::is\_floating\_point\_v<T>\` |
| `!`      | Negate a condition          | `!std::is_pointer_v<T>`         |                                     |                           |   |                                  |
