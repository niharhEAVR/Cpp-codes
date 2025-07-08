## 🧠 Fundamental Data Types and Their Sizes (in Bytes)

| **Data Type** | **Size**      | **Range (approx)**                         | **Example**              |
| ------------- | ------------- | ------------------------------------------ | ------------------------ |
| `bool`        | 1 byte        | `true` / `false`                           | `bool flag = true;`      |
| `char`        | 1 byte        | -128 to 127 (signed) / 0 to 255 (unsigned) | `char c = 'A';`          |
| `short`       | 2 bytes       | -32,768 to 32,767                          | `short s = 100;`         |
| `int`         | 4 bytes       | -2,147,483,648 to 2,147,483,647            | `int a = 12345;`         |
| `long`        | 4 bytes       | Same as int (on most systems)              | `long b = 999999;`       |
| `long long`   | 8 bytes       | \~ -9 quintillion to +9 quintillion        | `long long big = 1e18;`  |
| `float`       | 4 bytes       | \~ ±3.4 × 10⁻³⁸ to ±3.4 × 10³⁸             | `float pi = 3.14f;`      |
| `double`      | 8 bytes       | \~ ±1.7 × 10⁻³⁰⁸ to ±1.7 × 10³⁰⁸           | `double pi = 3.14159;`   |
| `long double` | 8 or 16 bytes | Depends on compiler and platform           | `long double x = 3.14L;` |

---

## 🧪 Want to See the Sizes on Your System?

Use this C++ code:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "bool: " << sizeof(bool) << " byte(s)" << endl;
    cout << "char: " << sizeof(char) << " byte(s)" << endl;
    cout << "short: " << sizeof(short) << " byte(s)" << endl;
    cout << "int: " << sizeof(int) << " byte(s)" << endl;
    cout << "long: " << sizeof(long) << " byte(s)" << endl;
    cout << "long long: " << sizeof(long long) << " byte(s)" << endl;
    cout << "float: " << sizeof(float) << " byte(s)" << endl;
    cout << "double: " << sizeof(double) << " byte(s)" << endl;
    cout << "long double: " << sizeof(long double) << " byte(s)" << endl;
    return 0;
}
```


### Output

```bash
bool: 1 byte(s)
char: 1 byte(s)
short: 2 byte(s)
int: 4 byte(s)
long: 4 byte(s)
long long: 8 byte(s)
float: 4 byte(s)
double: 8 byte(s)
long double: 16 byte(s)
```

---

## 🧭 Notes:

* These sizes can vary on different systems (32-bit vs 64-bit).
* `sizeof` returns the size in **bytes**.
* For portability, use `<cstdint>` types like `int32_t`, `int64_t`.
