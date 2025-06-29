# ✅ GOOD vs ❌ BAD Pointer Initialization

---

## ✅ GOOD: Initialize pointer with `nullptr`

```cpp
int* ptr = nullptr;
```

### 👍 Why it's good:

* `nullptr` is type-safe (better than just `0`).
* Clearly indicates "this pointer points to nothing right now".
* You can safely check:

```cpp
if (ptr != nullptr) {
    // safe to use *ptr
}
```

---

## ❌ BAD: Uninitialized pointer

```cpp
int* ptr; // ❌ undefined value
*ptr = 10; // ❌ crash or garbage write
```

### 😱 Why it's bad:

* `ptr` points **nowhere** (random garbage memory).
* Dereferencing causes **undefined behavior**, crashes, or hard-to-find bugs.


---

```cpp
int* ptr{};       // ✅ GOOD: ptr is initialized to nullptr
*ptr = 33;        // ❌ BAD: Dereferencing nullptr → crash!
```

### ✅ What's Good:

* `int* ptr{};` is **value-initialized** to `nullptr`, which means it's **not garbage**. That’s safer than:

  ```cpp
  int* ptr; // uninitialized (could contain any random value)
  ```

### ❌ What's Bad:

* You're trying to **write to the address** that `ptr` points to.
* But `ptr == nullptr`, meaning it points to **nothing**.
* Dereferencing `nullptr` is **undefined behavior**, usually causes a **crash (segmentation fault)**.

---

## ✅ GOOD: Initialize pointer to a valid variable

```cpp
int x = 5;
int* ptr = &x;
```

### 👍 Why it's good:

* `ptr` points to a valid memory address.
* Safe to read/write `*ptr`.

---

## ❌ BAD: Pointing to destroyed (out-of-scope) variable

```cpp
int* ptr;
{
    int x = 10;
    ptr = &x;
} // x is destroyed here
*ptr = 20; // ❌ Dangling pointer!
```

### 😱 Why it's bad:

* `ptr` becomes a **dangling pointer**.
* Memory is **freed**, but pointer still holds the address.
* Causes undefined behavior.

---

## ✅ GOOD: Using smart pointers (`std::unique_ptr`, `std::shared_ptr`)

```cpp
#include <memory>
std::unique_ptr<int> ptr = std::make_unique<int>(5);
```

### 👍 Why it's good:

* Automatically manages memory.
* No need for manual `delete`.
* Prevents memory leaks and dangling pointers.

---

## ❌ BAD: Forgetting to delete dynamically allocated memory

```cpp
int* ptr = new int(100);
// ... no delete
```

### 😱 Why it's bad:

* Causes a **memory leak**.
* Memory is reserved but **never released**.
* Can crash programs over time.

---

## ✅ GOOD: Setting pointer to `nullptr` after `delete`

```cpp
int* ptr = new int(10);
delete ptr;
ptr = nullptr; // 👍 safe
```

### 👍 Why it's good:

* Avoids **use-after-free** errors.
* Safe to check before accessing.

---

## ❌ BAD: Using pointer after deleting memory

```cpp
int* ptr = new int(10);
delete ptr;
*ptr = 20; // ❌ use-after-delete: undefined behavior
```

---

## 🧠 Summary Table

| Practice                      | Good? | Why?                           |
| ----------------------------- | ----- | ------------------------------ |
| `int* ptr = nullptr;`         | ✅     | Safe, clear it's uninitialized |
| `int* ptr;`                   | ❌     | Dangerous — garbage pointer    |
| `ptr = &x;`                   | ✅     | Points to valid memory         |
| `ptr = new int(10);`          | ⚠️    | OK, but needs `delete` later   |
| Not deleting dynamic memory   | ❌     | Memory leak                    |
| Using pointer after `delete`  | ❌     | Use-after-free bug             |
| `delete ptr; ptr = nullptr;`  | ✅     | Safe and clean                 |
| Smart pointers (`unique_ptr`) | ✅✅    | Best practice (C++11+)         |

---

## 🔧 Pro Tips:

* **Always initialize pointers**, even to `nullptr`.
* Avoid raw `new/delete`; use `std::unique_ptr` or `std::shared_ptr`.
* Never use a pointer after the memory is freed.
* Be extra careful when returning pointers from functions.
