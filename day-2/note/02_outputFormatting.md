### 🧠 What Does `flush` Actually Mean?

In C++, **`flush` means "force the output buffer to be written immediately."**

---

### 💡 What is an Output Buffer?

When you use `std::cout` to print something:

```cpp
std::cout << "Hello";
```

👉 It **doesn't always get printed to the screen right away**.
Instead, it's stored temporarily in an internal **output buffer** (a temporary memory area).

Why?

* **Performance**: Writing to the screen (or disk, file, etc.) is **slow**.
* So C++ tries to **group multiple outputs together** and send them in one go.

---

### 🔥 What Does `std::flush` Do?

`std::flush` **forces** whatever is in the buffer to be sent **immediately**, even if it’s not full.

#### Example:

```cpp
std::cout << "Processing..." << std::flush;
```

* The text `"Processing..."` is printed **right away**, without waiting for a newline (`\n`).
* Useful when you want the user to see real-time updates like:

  * loading bars
  * progress messages
  * debugging output

---

### 🔁 Difference Between `\n`, `std::endl`, and `std::flush`

| Expression   | Adds Newline? | Flushes Buffer? |
| ------------ | ------------- | --------------- |
| `\n`         | ✅ Yes         | ❌ No            |
| `std::endl`  | ✅ Yes         | ✅ Yes           |
| `std::flush` | ❌ No          | ✅ Yes           |


---
---
---


### 🔢 Part 1: The Variables

```cpp
double a{3.1415926535897932384626433832795};
double b{2006.0};
double c{1.34e-10};
```

* `a`: A value of Pi with many decimal digits.
* `b`: A normal large whole number stored as double.
* `c`: A very small number written in **scientific notation** (1.34 × 10⁻¹⁰).

---

### 📤 Part 2: Default Output

```cpp
std::cout << "double values (default : use scientific where necessary) : " << std::endl;
std::cout << "a : " << a << std::endl;
std::cout << "b : " << b << std::endl;
std::cout << "c : " << c << std::endl;
```

This prints all values in the **default format**, where:

* Normal values (like `a` and `b`) are printed in **fixed-point**.
* Very small or very large values (like `c`) are printed in **scientific notation** automatically.

Example output:

```
a : 3.14159
b : 2006
c : 1.34e-10
```

---

### 🛠 Part 3: `std::fixed`

```cpp
std::cout << std::fixed;
```

* Forces output to use **fixed-point notation** (not scientific).
* Even for tiny numbers like `c`, it prints in normal decimal format.

```cpp
std::cout << "a : " << a << std::endl;
std::cout << "b : " << b << std::endl;
std::cout << "c : " << c << std::endl;
```

Output might be:

```
a : 3.141593
b : 2006.000000
c : 0.000000000134
```

By default, it shows 6 digits **after the decimal point**.

---

### 🔬 Part 4: `std::scientific`

```cpp
std::cout << std::scientific;
```

* Forces all output into **scientific notation** format.

```cpp
std::cout << "a : " << a << std::endl;
std::cout << "b : " << b << std::endl;
std::cout << "c : " << c << std::endl;
```

Output might be:

```
a : 3.141593e+00
b : 2.006000e+03
c : 1.340000e-10
```

Again, 6 digits after the decimal by default.

---

### 🔁 Part 5: `unsetf(...)` — Reset Formatting

```cpp
std::cout.unsetf(std::ios::scientific | std::ios::fixed);
```

* This **turns off both `fixed` and `scientific` modes**.
* Output goes back to **default C++ behavior**, where:

  * "Normal" numbers use fixed-point
  * Very small/large numbers use scientific notation automatically

---

### 🧠 Summary Table

| Manipulator            | Description                               | Example Output (`a`)    |
| ---------------------- | ----------------------------------------- | ----------------------- |
| *Default (no setting)* | Smart: fixed or scientific based on value | `3.14159`               |
| `std::fixed`           | Always fixed-point, 6 decimals            | `3.141593`              |
| `std::scientific`      | Always scientific notation, 6 decimals    | `3.141593e+00`          |
| `unsetf(...)`          | Remove both fixed and scientific          | Back to auto-formatting |

---

### ✅ Bonus: Controlling Precision

You can also use:

```cpp
std::cout << std::setprecision(3);
```

To control how many **total digits** are printed. But you must include `<iomanip>`.
