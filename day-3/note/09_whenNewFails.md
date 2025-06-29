## ❓ What Is `new` in C++?

`new` is used to **dynamically allocate memory** on the **heap**.

```cpp
int* p = new int(10); // Allocates memory and stores 10
```

Normally it works fine, but it **can fail** if memory can't be allocated.

---

## ⚠️ What Happens When `new` Fails?

### 🔹 By Default:

If memory **cannot be allocated**, the `new` operator:

* **Throws a `std::bad_alloc` exception** (from `<new>` header)

### Example:

```cpp
#include <iostream>
#include <new> // for std::bad_alloc

int main() {
    try {
        // Try to allocate a huge amount of memory
        int* data = new int[100000000000000];
    } catch (std::bad_alloc& e) {
        std::cerr << "Allocation failed: " << e.what() << std::endl;
    }
}
```

**Output:**

```
Allocation failed: std::bad_alloc
```

---

## 🤯 Why `new` Fails?

1. **System Out of Memory (OOM):**

   * You're asking for **more RAM than available**.
   * Common in large array allocations or memory leaks.

2. **Memory Fragmentation:**

   * Enough memory may exist, but not in **one continuous block**.

3. **System Limits:**

   * OS may **limit heap size per process** (especially on 32-bit systems).

4. **Recursive Allocation:**

   * You accidentally keep allocating memory without freeing it → memory leak → crash.

---

## ✅ How to Handle/Resolve `new` Failure

### ✅ 1. Use Try-Catch for Safety

```cpp
try {
    int* p = new int[100000000000000];
} catch (std::bad_alloc& e) {
    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
}
```

This is the **standard safe way** to catch allocation failure.

---

### ✅ 2. Use `new (nothrow)` to Avoid Exceptions

```cpp
#include <new>

int* p = new(std::nothrow) int[100000000000000];
if (!p) {
    std::cerr << "Allocation failed (nothrow)" << std::endl;
}
```

* ✅ No exception will be thrown.
* ✅ If allocation fails, `p` becomes `nullptr`.

---

### ✅ 3. Always Delete What You `new`

Memory leaks reduce available memory over time:

```cpp
int* p = new int(5);
// use it...
delete p; // free it!
```

🧠 Use **smart pointers** (`std::unique_ptr`, `std::shared_ptr`) to manage memory automatically.

---

### ✅ 4. Avoid Over-Allocating

Sometimes this fails:

```cpp
int* big_array = new int[INT_MAX];
```

Try:

* Smaller chunks
* `std::vector<int>` (handles resizing better)
* Check `sizeof()` before allocating

---

## 🔄 Summary Table

| Situation               | What Happens            | How to Handle                                        |
| ----------------------- | ----------------------- | ---------------------------------------------------- |
| `new` fails             | Throws `std::bad_alloc` | Use `try-catch`                                      |
| You use `new (nothrow)` | Returns `nullptr`       | Check pointer before use                             |
| You overallocate        | May crash system        | Allocate smaller or use containers                   |
| Memory leak             | Memory keeps filling    | Always `delete` what you `new` or use smart pointers |
