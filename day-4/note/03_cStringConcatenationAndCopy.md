## 🔹 Code Recap

```cpp
const char *source3 = "C++ is a multipurpose programming language.";
char *dest3 = new char[std::strlen(source3) + 1];  // allocate memory (+1 for '\0')

std::strcpy(dest3, source3);  // copy content from source3 to dest3

std::cout << "sizeof(dest3) : " << sizeof(dest3) << std::endl;
std::cout << "std::strlen(dest3) : " << std::strlen(dest3) << std::endl;
std::cout << "dest3 : " << dest3 << std::endl;

delete dest3;
dest3 = nullptr;
```

---

## ✅ Step-by-Step Breakdown

---

### 🔹 Step 1: Create Source

```cpp
const char *source3 = "C++ is a multipurpose programming language.";
```

* `source3` points to a string literal.
* Stored in **read-only memory** (not writable).
* Contents:
  `"C++ is a multipurpose programming language."`
  Length = 46 characters (including spaces), not counting `\0`

---

### 🔹 Step 2: Allocate Memory for Destination

```cpp
char *dest3 = new char[std::strlen(source3) + 1];
```

* `std::strlen(source3)` returns 46 (number of visible characters).
* `+1` → space for the null terminator `\0`.
* So you're allocating `47` bytes on the **heap**.

✅ At this point:

* `dest3` points to uninitialized garbage.
* It's a block of memory large enough to hold the entire string.

---

### 🔹 Step 3: Copy Using `std::strcpy`

```cpp
std::strcpy(dest3, source3);
```

* This copies **all characters** (plus the null `\0`) from `source3` into `dest3`.
* Now `dest3` holds a copy of the original string in heap memory.

✅ After this:

```cpp
dest3 == "C++ is a multipurpose programming language."
```

---

### 🔹 Step 4: Output `sizeof(dest3)`

```cpp
std::cout << "sizeof(dest3) : " << sizeof(dest3) << std::endl;
```

🛑 ⚠️ **Common confusion here!**

* `sizeof(dest3)` is **NOT** the size of the string.
* `dest3` is a pointer (`char*`) → `sizeof(dest3)` = size of a pointer.

  * On a 64-bit machine: typically **8**
  * On a 32-bit machine: typically **4**

✅ So this prints:

```
sizeof(dest3) : 8
```

(It doesn’t care how much memory you allocated.)

---

### 🔹 Step 5: Output `std::strlen(dest3)`

```cpp
std::cout << "std::strlen(dest3) : " << std::strlen(dest3) << std::endl;
```

* `strlen()` walks from `dest3` until it hits `\0` and counts characters.
* The string is: `"C++ is a multipurpose programming language."` = 46 characters

✅ So this prints:

```
std::strlen(dest3) : 46
```

---

### 🔹 Step 6: Output the String

```cpp
std::cout << "dest3 : " << dest3 << std::endl;
```

* Since `dest3` now holds a null-terminated string, this prints:

```
dest3 : C++ is a multipurpose programming language.
```

---

### 🔹 Step 7: Cleanup

```cpp
delete dest3;
dest3 = nullptr;
```

* `new[]` was used → this should be `delete[]` (⚠️ Bug)
* Using `delete` instead of `delete[]` for array is **undefined behavior**

✅ It should be:

```cpp
delete[] dest3;
```

---

## ✅ Summary of Outputs

| Expression           | Output / Meaning                                            |
| -------------------- | ----------------------------------------------------------- |
| `sizeof(dest3)`      | 8 (on 64-bit) → Size of pointer, **not** string             |
| `std::strlen(dest3)` | 46 → Length of copied string (up to but not including `\0`) |
| `dest3`              | `"C++ is a multipurpose programming language."`             |
| `delete dest3;`      | ❌ Wrong – should be `delete[] dest3;`                       |

---

## 🔧 Fix the Code

Here's the corrected version:

```cpp
const char *source3 = "C++ is a multipurpose programming language.";
char *dest3 = new char[std::strlen(source3) + 1];  // allocate memory

std::strcpy(dest3, source3);

std::cout << "sizeof(dest3) : " << sizeof(dest3) << std::endl; // prints 8
std::cout << "std::strlen(dest3) : " << std::strlen(dest3) << std::endl; // prints 46
std::cout << "dest3 : " << dest3 << std::endl;

delete[] dest3; // ✅ correct delete
dest3 = nullptr;
```