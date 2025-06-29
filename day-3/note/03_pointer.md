## 🧠 What is a Pointer?

A **pointer** is a variable that **stores the memory address** of another variable.

---

## 📍 Why are Pointers Important?

* Access and manipulate memory directly
* Efficient array and string handling
* Used in dynamic memory allocation
* Crucial for data structures (like linked lists, trees)
* Required for functions that modify original variables (pass by reference)

---

## 🧱 Basic Syntax

```cpp
int x = 10;
int* ptr = &x;  // 'ptr' stores the address of x
```

### Breakdown:

* `int* ptr;` → declares a pointer to an int.
* `&x` → address-of operator: gives the address of variable `x`.
* `*ptr` → dereference operator: gives the value stored at the address.

---

## 🧪 Example Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int* ptr = &x;

    cout << "Value of x     : " << x << endl;        // 42
    cout << "Address of x   : " << &x << endl;       // e.g. 0x7ffe...
    cout << "Value of ptr   : " << ptr << endl;      // same as &x
    cout << "Value at ptr   : " << *ptr << endl;     // 42
    return 0;
}
```

---

## 🔄 Pointers and Functions

### 🧍‍♂️ Pass by Value (Copy)

```cpp
void update(int a) {
    a = 100;
}
```

### 🔁 Pass by Pointer (Modify original)

```cpp
void update(int* a) {
    *a = 100;
}

int main() {
    int x = 10;
    update(&x);
    cout << x;  // 100
}
```

---

## 🧩 Pointer to Pointer

```cpp
int x = 5;
int* p = &x;
int** pp = &p;

cout << **pp << endl;  // 5
```

---

## 📦 Arrays and Pointers

```cpp
int arr[] = {10, 20, 30};
int* p = arr;

cout << *(p + 1);  // 20
```

`arr[i]` is same as `*(arr + i)`.

---

## 🧠 Dynamic Memory Allocation (Heap)

```cpp
int* ptr = new int(25);
cout << *ptr;  // 25
delete ptr;    // Always delete to free memory
```

### For Arrays:

```cpp
int* arr = new int[5];  // dynamic array of 5 ints
delete[] arr;
```

---

## 🧯 Null Pointer

```cpp
int* ptr = nullptr;  // points to nothing
```

Useful for checking:

```cpp
if (ptr != nullptr) {
    // safe to use *ptr
}
```

---

## ❌ Dangling Pointer

```cpp
int* ptr;
{
    int x = 10;
    ptr = &x;
}
// x is destroyed here; ptr is now dangling
```

Never use a pointer after its variable is destroyed.

---

## 🧱 Pointer vs Reference

| Feature              | Pointer    | Reference          |
| -------------------- | ---------- | ------------------ |
| Syntax               | `int* ptr` | `int& ref`         |
| Can be null          | ✅ Yes      | ❌ No               |
| Can reassign         | ✅ Yes      | ❌ No (after init)  |
| Requires `&` and `*` | ✅ Yes      | ❌ No (transparent) |

---

## ✅ Summary

* A pointer holds a memory address.
* Use `&` to get the address and `*` to access the value at that address.
* Crucial for dynamic memory, arrays, and advanced data structures.
* Must handle carefully to avoid memory leaks, dangling, or null pointers.

---
---
---



# ✅ 1. **Pointer Arithmetic**

Pointer arithmetic lets you move through memory locations—especially useful with arrays.

### 🧪 Example:

```cpp
int arr[] = {10, 20, 30};
int* p = arr;

std::cout << *p << std::endl;     // 10
std::cout << *(p + 1) << std::endl; // 20
std::cout << *(p + 2) << std::endl; // 30
```

### 🧠 How it works:

* `p + 1` moves the pointer by **1 int** (not 1 byte).
* So it automatically moves `4 bytes` (on most systems).

### Arithmetic operations supported:

* `p + n`
* `p - n`
* `p1 - p2` (distance between two pointers)
* Comparison (`p1 < p2`)

---

# ✅ 2. **Function Pointers**

Function pointers allow you to store the address of a function and call it dynamically.

### 🧪 Example:

```cpp
#include <iostream>
using namespace std;

void greet() {
    cout << "Hello!" << endl;
}

int add(int a, int b) {
    return a + b;
}

int main() {
    void (*fptr1)() = greet;         // Pointer to function with no args
    int (*fptr2)(int, int) = add;    // Pointer to function with two ints

    fptr1();                         // Calls greet()
    cout << fptr2(3, 4);             // Calls add(3, 4)
}
```

### 📌 Real-World Use:

* Callbacks
* Event handling
* Menu-driven programs
* Strategy patterns

---

# ✅ 3. **Smart Pointers (C++11 and above)**

Smart pointers **automatically manage memory**, preventing memory leaks.

### 🧪 `unique_ptr`

```cpp
#include <memory>
std::unique_ptr<int> uptr = std::make_unique<int>(42);
```

* Owns memory exclusively.
* Auto-deletes when it goes out of scope.
* Cannot be copied (only moved).

---

### 🧪 `shared_ptr`

```cpp
#include <memory>
std::shared_ptr<int> sptr1 = std::make_shared<int>(100);
std::shared_ptr<int> sptr2 = sptr1; // Both share ownership
```

* Keeps a **reference count**.
* Memory freed only when last shared\_ptr is destroyed.

---

### 🧪 `weak_ptr`

```cpp
std::weak_ptr<int> wptr = sptr1;
```

* Doesn’t increase ref count.
* Used to break circular dependencies.

---

# ✅ 4. **Linked List using Pointers**

### 🧪 Basic singly linked list

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};

    printList(head);
}
```

### 🧠 Memory management:

* Dynamically allocated nodes using `new`
* Clean-up needed using `delete` (or use smart pointers)

---

# ✅ Summary

| Topic              | What It Does                                  |
| ------------------ | --------------------------------------------- |
| Pointer Arithmetic | Move through arrays/memory                    |
| Function Pointers  | Store & call functions dynamically            |
| Smart Pointers     | Manage memory automatically                   |
| Linked List        | Real use-case for pointers in data structures |
