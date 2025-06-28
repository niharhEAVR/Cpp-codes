## 📘 Include This First

Before using math functions, always include:

```cpp
#include <cmath>
```

---

## ✅ 1. **Basic Functions**

| Function   | Description                       | Example      | Output |
| ---------- | --------------------------------- | ------------ | ------ |
| `abs(x)`   | Absolute value (int overload)     | `abs(-5)`    | `5`    |
| `fabs(x)`  | Absolute value (float/double)     | `fabs(-5.4)` | `5.4`  |
| `ceil(x)`  | Round **up** to nearest integer   | `ceil(4.2)`  | `5`    |
| `floor(x)` | Round **down** to nearest integer | `floor(4.8)` | `4`    |
| `round(x)` | Round to nearest integer          | `round(4.6)` | `5`    |
| `trunc(x)` | Drop decimal (truncate)           | `trunc(4.9)` | `4`    |

---

## 🧮 2. **Power and Root**

| Function      | Description                  | Example       | Output |
| ------------- | ---------------------------- | ------------- | ------ |
| `pow(x, y)`   | Raise x to power y           | `pow(2, 3)`   | `8`    |
| `sqrt(x)`     | Square root                  | `sqrt(16)`    | `4`    |
| `cbrt(x)`     | Cube root                    | `cbrt(27)`    | `3`    |
| `hypot(x, y)` | √(x² + y²) (like Pythagoras) | `hypot(3, 4)` | `5`    |

---

## 📏 3. **Logarithmic and Exponential**

| Function   | Description      | Example        | Output    |
| ---------- | ---------------- | -------------- | --------- |
| `exp(x)`   | eˣ               | `exp(1)`       | `2.71828` |
| `log(x)`   | Natural log (ln) | `log(2.71828)` | `~1`      |
| `log10(x)` | Log base 10      | `log10(1000)`  | `3`       |
| `log2(x)`  | Log base 2       | `log2(8)`      | `3`       |

---

## 📐 4. **Trigonometric (Radians)**

| Function      | Description                           | Example         | Output   |
| ------------- | ------------------------------------- | --------------- | -------- |
| `sin(x)`      | Sine (x in radians)                   | `sin(3.14 / 2)` | `~1`     |
| `cos(x)`      | Cosine                                | `cos(0)`        | `1`      |
| `tan(x)`      | Tangent                               | `tan(0.5)`      | `~0.546` |
| `asin(x)`     | Inverse sine                          | `asin(1)`       | `~1.57`  |
| `acos(x)`     | Inverse cosine                        | `acos(0)`       | `~1.57`  |
| `atan(x)`     | Inverse tangent                       | `atan(1)`       | `~0.785` |
| `atan2(y, x)` | Arctangent of y/x (handles quadrants) | `atan2(1, 1)`   | `~0.785` |

> Use `#define _USE_MATH_DEFINES` before `#include <cmath>` to get `M_PI`.

---

## 📐 5. **Angle Conversions**

| Function                           | Description |
| ---------------------------------- | ----------- |
| `degrees = radians * (180 / M_PI)` |             |
| `radians = degrees * (M_PI / 180)` |             |

---

## 🎲 6. **Remainder / Modulo**

| Function         | Description                      | Example             | Output |
| ---------------- | -------------------------------- | ------------------- | ------ |
| `fmod(x, y)`     | Floating-point remainder (x % y) | `fmod(7.5, 2)`      | `1.5`  |
| `remainder(x,y)` | IEEE remainder (can be negative) | `remainder(7.5, 2)` | `-0.5` |

---

## 🧪 7. **Other Useful Ones**

| Function                  | Description                          |
| ------------------------- | ------------------------------------ |
| `std::min(x, y)`          | Minimum of two values                |
| `std::max(x, y)`          | Maximum of two values                |
| `std::clamp(val, lo, hi)` | Clamp value to range                 |
| `std::copysign(x, y)`     | Copy the sign of `y` to `x`          |
| `std::isnan(x)`           | Check if value is NaN (not a number) |
| `std::isinf(x)`           | Check if value is infinite           |
| `std::signbit(x)`         | Returns 1 if x is negative           |

> You may need `<algorithm>` for `min`, `max`, and `<cmath>` for others.

---
---


```cpp
std::cout << "Log : to get 54.59, you would elevate e to the power of : " << std::log(54.59) << std::endl;
```

---

### 🧠 What It's Doing:

This line prints **the natural logarithm (log base `e`)** of `54.59`.

---

### 🧮 Math Behind It:

We know:

```text
e⁴ ≈ 54.59
```

So to reverse that, you're asking:

> "**To what power** should I raise `e` to get `54.59`?"

Answer:

```cpp
logₑ(54.59) = 4
```

This is what `std::log()` in C++ does!

* `std::log(x)` means:
  👉 **log base `e`** of `x`
  👉 Also called the **natural logarithm**

So:

```cpp
std::log(54.59) ≈ 4.0
```

---

### 📦 Output:

```
Log : to get 54.59, you would elevate e to the power of : 4
```

Meaning:

> "If I raise `e` to the power `4`, I will get 54.59."

---

### 🧪 Verify in Reverse:

```cpp
std::cout << "e^4 = " << std::exp(4) << std::endl;
```

* `std::exp(x)` → returns `eˣ`
* Output will be: `54.5981...`
