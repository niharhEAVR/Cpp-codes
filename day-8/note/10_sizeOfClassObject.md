## 🔍 First: **What is the size of a class object?**

In C++, the size of a class object (i.e., `sizeof(dog1)`) is determined by:

### ✅ Only **non-static data members** contribute to its size.

That means:

* **Member variables** take space ✅
* **Member functions** do **not** take space ❌
* **Access specifiers (`public`, `private`)** don’t matter ❌
* **Padding and alignment** **do** matter ✅

---

## 📦 Your Class Breakdown:

```cpp
class Dog
{
public:
    void prin_info() {}   // ❌ Doesn't affect object size
    void do_something() {} // ❌ Doesn't affect object size

private:
    size_t leg_count; // ✅ Takes 8 bytes (on 64-bit)
    size_t arm_count; // ✅ Takes 8 bytes (on 64-bit)
    int *p_age;       // ✅ Takes 8 bytes (pointer on 64-bit)
};
```

### 🔢 Expected Size:

| Member        | Type     | Size (bytes)                          |
| ------------- | -------- | ------------------------------------- |
| leg\_count    | `size_t` | 8                                     |
| arm\_count    | `size_t` | 8                                     |
| p\_age        | `int*`   | 8                                     |
| **Total raw** |          | **24 bytes**                          |
| **+ Padding** | (maybe)  | **None or minimal** (already aligned) |

So `sizeof(Dog)` is expected to be **24 bytes** on a **64-bit system**.

---

## 🧠 Now Let's Explain Your Code Step by Step

```cpp
#include <iostream>
```

* You include I/O support to use `std::cout`.

---

### 🔷 Class Definition

```cpp
class Dog {
public:
    void prin_info() {}
    void do_something() {}

private:
    size_t leg_count;
    size_t arm_count;
    int* p_age;
};
```

* You define a class `Dog` with:

  * Two functions — they **don't affect object size**
  * Three member variables:

    * Two `size_t` — 8 bytes each
    * One `int*` — 8 bytes (pointer)
  * Total: **24 bytes**

---

### 🔷 `main()` Function

```cpp
Dog dog1;
```

* Creates an object of type `Dog`.
* It has 3 data members as shown above.

---

### 🖨️ You Print Sizes

```cpp
std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl;
```

* Will print: `8` (on 64-bit systems)

```cpp
std::cout << "sizeof(int*) : " << sizeof(int *) << std::endl;
```

* Will also print: `8` (pointer size on 64-bit)

```cpp
std::cout << "sizeof(Dog) : " << sizeof(dog1) << std::endl;
```

* Prints: `24` (expected) — based on 3 data members.

---


```cpp
#include <iostream>
#include <string>

int main() {
    std::string name{"I am the king of the universe!"};

    std::cout << "sizeof(name) : " << sizeof(name) << std::endl;
}
```


### 🔹 What happens here?

* `name` is an object of type `std::string`.
* `sizeof(name)` gives you the size of the **`std::string` object itself**, **not** the length of the text it stores.

⚠️ That’s the key:

* `std::string` doesn’t store all characters directly inside itself.
* It usually stores a **pointer to heap memory**, plus some bookkeeping info (length, capacity).

So the `sizeof` just measures that internal structure.


### 🔹 Typical output

On most 64-bit systems, `sizeof(std::string)` is **24** or **32** bytes (depends on compiler and implementation).

For example:

* GCC/libstdc++ (Linux) → 32 bytes
* MSVC (Windows) → 32 bytes
* Clang/libc++ → 24 bytes

Even though your text `"I am the king of the universe!"` has **30 characters**, `sizeof(name)` won’t be 30 — it’ll be a fixed small number like 24 or 32.

### 🔹 To get actual string length:

```cpp
std::cout << "name.size() : " << name.size() << std::endl;
```

That would print **30**, the number of characters in the string.


✅ So:

* `sizeof(name)` → memory footprint of the `std::string` object itself.
* `name.size()` → number of characters stored in the string.

---

## ✅ Final Output (on 64-bit system):

```
sizeof(size_t) : 8
sizeof(int*) : 8
sizeof(Dog) : 24
sizeof(name) : 32
```

---

## 📌 Final Notes

### 🧠 Summary Table:

| Thing                     | Why it takes space?           | Size (64-bit)           |
| ------------------------- | ----------------------------- | ----------------------- |
| `size_t`                  | Primitive type                | 8 bytes                 |
| `int*`                    | Pointer to int                | 8 bytes                 |
| Member function           | Shared by all objects         | 0 bytes                 |
| `std::string` object      | Holds pointer, size, capacity | \~32 bytes              |
| `std::string` actual text | Stored on heap                | Not counted in `sizeof` |


---
---
---


## ✅ Yes: On a 64-bit system, `int` is still **4 bytes (32 bits)**

That’s **completely normal** and expected — here's why:

---

## 📌 C++ Type Sizes Are **Not Automatically Scaled** on 64-bit

In C and C++, **only pointer-related types** (like `size_t`, `int*`, `void*`, etc.) are guaranteed to grow in size to match the platform's address space. But **fundamental types** like `int`, `short`, `char`, and even `long` do **not automatically change size** when switching from 32-bit to 64-bit.

---

## 🧠 Explanation: Why `int` is Still 4 Bytes on 64-bit

### Most 64-bit systems follow the **LP64 model** (Linux/macOS/Unix):

| Type        | Size (in bytes) |
| ----------- | --------------- |
| `char`      | 1               |
| `short`     | 2               |
| `int`       | 4               |
| `long`      | 8               |
| `long long` | 8               |
| `void*`     | 8               |
| `size_t`    | 8               |

> So on a 64-bit system:
>
> * `int` is still **32 bits (4 bytes)**
> * `long` and pointers grow to **64 bits (8 bytes)**

This is to ensure **compatibility** with existing 32-bit programs, and because `int` is usually "big enough" for most normal operations (e.g., indexing, looping, basic math).

---

### 🔢 Compare: `int` vs `size_t`

| Type     | Purpose                        | Size on 64-bit |
| -------- | ------------------------------ | -------------- |
| `int`    | General-purpose signed integer | 4 bytes        |
| `size_t` | For indexing, memory size      | 8 bytes        |
| `int*`   | Pointer to int                 | 8 bytes        |

---

## ✅ So Why Is `size_t` 8 Bytes But `int` Only 4?

Because:

* `size_t` is meant to store **sizes of objects and indexes**, which may be as big as 2⁶⁴ bytes on a 64-bit system → needs 8 bytes.
* `int` is just a **basic integer type**, not tied to memory size → doesn’t need to change.

---

## 🚀 If You Want a 64-bit Integer?

Use:

```cpp
int64_t bigInt;       // Signed 64-bit int
uint64_t bigCount;    // Unsigned 64-bit int
```

These are from `<cstdint>` or `<stdint.h>` and guarantee the size.

---

## ✅ Summary

| Type     | Size (on 64-bit) | Why it is this size                       |
| -------- | ---------------- | ----------------------------------------- |
| `int`    | 4 bytes          | Traditional size, for general-purpose use |
| `size_t` | 8 bytes          | Matches pointer size, needed for indexing |
| `int*`   | 8 bytes          | Must store full 64-bit address            |
| `void*`  | 8 bytes          | Same — holds memory addresses             |
