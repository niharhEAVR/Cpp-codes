## ✅ First: What are `std::dec`, `std::hex`, `std::oct`?

These are **format flags** used with `std::cout` to change the **base of output**:

| Flag       | Means       | Applies To |
| ---------- | ----------- | ---------- |
| `std::dec` | Decimal     | Integers   |
| `std::hex` | Hexadecimal | Integers   |
| `std::oct` | Octal       | Integers   |

---

## ❗ So Why Don't They Work on `double`?

Because these **base manipulators (`hex`, `oct`, `dec`) only affect integer types**.

### 🧠 Floating-point (`float`, `double`) numbers are always printed in **decimal** or **scientific** format — never in hex or oct — **unless you specifically ask for a hex representation** using something else.

Example:

```cpp
double d = 3.14;
std::cout << std::hex << d << std::endl;
```

Even though `std::hex` is there, you'll still see:

```
3.14
```

Because **hex has no effect on `double`**.

---

## ✅ Want Hex Output of a Double?

If you really want to see the **actual binary (or hex) representation** of a `double`, you need to **reinterpret it as an integer**.

### Example:

```cpp
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cstring>

int main() {
    double d = 3.14;
    uint64_t bits;
    std::memcpy(&bits, &d, sizeof(d));  // Copy raw bits
    std::cout << "Raw hex of 3.14: 0x" << std::hex << bits << std::endl;
}
```

Output:

```
Raw hex of 3.14: 0x40091eb851eb851f
```

This is the **actual 64-bit IEEE 754 binary format of 3.14**.

---

## ✅ Summary:

| Statement                            | Explanation                                         |
| ------------------------------------ | --------------------------------------------------- |
| `std::hex << double_var`             | Has no effect — double is always printed in decimal |
| `std::hex << int_var`                | Works — int is printed in hexadecimal               |
| To see hex of `double`, use `memcpy` | Required to see the raw bit-level representation    |


---
---
---



### 🔬 `std::scientific`

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


