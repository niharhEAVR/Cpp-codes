> ✅ **Memory leaks** — which happen when **dynamically allocated memory is not freed**, and your program **loses access to it**.

## ✅ What is a Memory Leak?

A **memory leak** occurs when:

* You **allocate memory using `new`** (on the heap),
* But you **don’t call `delete`** to free it, and
* You **lose the pointer** to that memory.

👉 The memory is still "reserved" in RAM, but **your program can't access or reuse it anymore**.

🧠 The leaked memory builds up over time → can crash the program or slow down the system.

---

## 🔍 Let's Go Through Each Code Block

---

### 🧨 1. **Pointer Overwrite Without Deletion**

```cpp
int *p_number {new int{67}}; // Heap memory allocated — let's call this address1

int number{55};              // Stack variable
p_number = &number;          // Now p_number points to a different address (stack address2)
```

#### ❗ What's wrong here?

* `new int{67}` creates memory on heap (say address1).
* But you **overwrite `p_number` with a new address (address2)**.
* So:

  * The memory at `address1` is still allocated.
  * But you **lost all pointers to it** → 🔥 memory leak.

#### ✅ How to fix:

```cpp
delete p_number;    // free the memory before changing what the pointer points to
p_number = &number; // safe now
```

---

### 🧨 2. **Double Allocation Without Deletion**

```cpp
int *p_number1 {new int{55}};  // address1
p_number1 = new int{44};       // address2 — memory from address1 is now leaked!
```

#### ❗ What happened?

* First allocation creates memory for `55` → address1.
* Then you reassign a new memory (`44`) to the same pointer → address2.
* But `delete` was **not called on address1** before reassignment → 🔥 memory leak.

#### ✅ How to fix:

```cpp
delete p_number1;             // delete address1 before reassigning
p_number1 = new int{44};      // safe now
```

Or, even better:

```cpp
int* p_number1 = new int{55};
// use it
delete p_number1;

p_number1 = new int{44}; // safe reuse
// use it
delete p_number1;
```

---

### 🧨 3. **Dynamically Allocated Memory Inside Scope**

```cpp
{
    int *p_number2 {new int{57}};
    // use p_number2
} // p_number2 goes out of scope here
```

#### ❗ What's the problem?

* `new int{57}` allocates memory on heap.
* `p_number2` is a local pointer — when it goes out of scope, it’s **destroyed automatically**.
* But the heap memory it pointed to is **NOT freed** — 🔥 memory leak again.

#### ✅ How to fix:

```cpp
{
    int* p_number2 = new int{57};
    // use it
    delete p_number2; // before going out of scope
}
```

---

## 🛑 Real-World Impact of Memory Leaks

* Over time, leaks consume system RAM.
* Leads to **slowdowns**, **crashes**, or **out-of-memory errors**.
* In long-running apps (e.g., servers, games), even tiny leaks are dangerous.

---

## 🧠 Rule of Thumb

Whenever you use `new`, make sure to **pair it with `delete`** once you're done.

| `new`        | `delete`      |
| ------------ | ------------- |
| `new[]`      | `delete[]`    |
| `new T(...)` | `delete ptr;` |

---

## ✅ Best Practice: Use Smart Pointers

Modern C++ prefers using **smart pointers**:

```cpp
#include <memory>

void demo() {
    std::unique_ptr<int> ptr = std::make_unique<int>(57);
    // Automatically deallocated when 'ptr' goes out of scope
}
```

* ✅ No manual `delete`
* ✅ No memory leaks
* ✅ Safe and clean

---

## 🔚 Summary

| Type of Leak                         | Why It Happens                    | Fix                                       |
| ------------------------------------ | --------------------------------- | ----------------------------------------- |
| Overwriting pointer without `delete` | Loses reference to heap           | Call `delete` before reassigning          |
| Double allocation without cleanup    | Old heap memory is lost           | Call `delete` before new `new`            |
| Scope exit without deletion          | Pointer dies, memory stays        | `delete` before pointer goes out of scope |
| General best practice                | Using raw `new`/`delete` is risky | Use smart pointers instead                |
