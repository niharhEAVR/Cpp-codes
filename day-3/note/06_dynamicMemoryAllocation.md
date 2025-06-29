# 🧠 What is Dynamic Memory Allocation?

Dynamic memory allocation means **reserving memory at runtime** (not at compile time), usually when:

* You don't know in advance how much memory you’ll need.
* You want to create data structures (arrays, linked lists, etc.) whose size can change.

---

# 🔧 Static vs Dynamic Allocation

| Feature         | Static Allocation     | Dynamic Allocation        |
| --------------- | --------------------- | ------------------------- |
| Memory size     | Known at compile time | Decided at runtime        |
| Memory location | Stack                 | Heap (free store)         |
| Lifetime        | Automatically managed | Must manage manually      |
| Syntax          | `int arr[10];`        | `int* arr = new int[10];` |

---

# ✅ Syntax for Dynamic Memory

### 🧱 1. Allocate memory

```cpp
int* p = new int;         // Single integer
int* arr = new int[5];    // Array of 5 integers
```

### 💾 2. Use the memory

```cpp
*p = 10;
arr[0] = 1;
arr[1] = 2;
```

### 🧹 3. Free the memory

```cpp
delete p;         // For single variable
delete[] arr;     // For array
```

> 🔥 **Important**: If you forget to `delete`, it causes a **memory leak**.

---

## 🧪 Example Program: Dynamic Integer

```cpp
#include <iostream>
using namespace std;

int main() {
    int* p = new int;   // allocate 1 int on heap
    *p = 42;

    cout << "Value: " << *p << endl;

    delete p;           // free memory
    return 0;
}
```

---

## 🧪 Example Program: Dynamic Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];  // allocate array on heap

    for (int i = 0; i < size; ++i)
        arr[i] = i * 10;

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";

    delete[] arr;  // free memory
    return 0;
}
```

---

# ❌ Common Mistakes

### 1. **Memory leak**

```cpp
int* p = new int(5);
// forgot delete → memory leak!
```

### 2. **Use-after-delete**

```cpp
int* p = new int(10);
delete p;
*p = 20; // ❌ undefined behavior
```

### 3. **Dereferencing nullptr**

```cpp
int* p = nullptr;
*p = 10; // ❌ crash!
```

---

# ✅ Modern C++ Alternative: Smart Pointers

### 🔐 `std::unique_ptr` (C++11)

```cpp
#include <memory>
auto p = std::make_unique<int>(5);
// auto-deletes when out of scope
```

### 🔄 `std::shared_ptr`

```cpp
#include <memory>
auto p = std::make_shared<int>(10);
// shared ownership with reference counting
```

---

# ✅ Summary

| Operation    | Syntax                               |
| ------------ | ------------------------------------ |
| Allocate     | `new int`, `new int[10]`             |
| Deallocate   | `delete`, `delete[]`                 |
| Safer Option | `std::unique_ptr`, `std::shared_ptr` |
