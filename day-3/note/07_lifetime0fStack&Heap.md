In C++, **stack** and **heap** memory have different *lifetimes*, *scopes*, and *management mechanisms*. Let's break it down clearly.

---

## 🔷 Stack Memory

### 🧠 What it is:

* Managed **automatically** by the compiler.
* Used for **local variables**, **function parameters**, **return addresses**.
* Follows **Last In, First Out (LIFO)** order.

### ⏳ Lifetime:

* The lifetime of a stack variable starts when the function is called, and ends when the function exits.

### 📦 Example:

```cpp
void func() {
    int a = 10; // 'a' is allocated on the stack
    // 'a' lives until the end of this function
} // 'a' is automatically destroyed here
```

### ✅ Pros:

* Very fast allocation/deallocation.
* Automatically managed.
* No memory leaks (since variables are destroyed automatically).

### ❌ Cons:

* Limited memory (usually a few MB).
* Cannot manually control the lifetime.

---

## 🔷 Heap Memory (Dynamic Memory)

### 🧠 What it is:

* Managed **manually** by the programmer.
* Used when you use `new`, `malloc`, or `std::vector`, etc.
* Not tied to any function call or scope.

### ⏳ Lifetime:

* Starts when you explicitly allocate memory using `new` or `malloc`.
* Ends when you manually deallocate using `delete` or `free`.

### 📦 Example:

```cpp
void func() {
    int* p = new int(20); // Memory allocated on heap
    // 'p' is a pointer on stack, but points to heap memory
    delete p; // Must manually free it
}
```

If you **forget `delete`**, the memory stays allocated: 🧠 **Memory Leak**

### ✅ Pros:

* Large memory (can be GBs).
* You can control when memory is allocated and deallocated.

### ❌ Cons:

* Slower than stack.
* Needs manual cleanup (or smart pointers like `std::unique_ptr`).
* Risk of memory leaks or dangling pointers.

---

## 🔁 Comparison Table:

| Feature          | Stack                   | Heap                    |
| ---------------- | ----------------------- | ----------------------- |
| Allocation Speed | Fast                    | Slower                  |
| Lifetime         | Auto (until scope ends) | Manual (until `delete`) |
| Size             | Small                   | Large                   |
| Management       | Compiler                | Programmer              |
| Safety           | Safe (auto cleanup)     | Risky (manual cleanup)  |

---

## 👀 Visualization:

```
Memory Layout:
+---------------------------+
|   Code Segment            | <- Instructions
+---------------------------+
|   Static / Global Memory  | <- Global/static vars
+---------------------------+
|   Heap                    | <- Dynamic memory (grows up)
|                           |
|                           |
|                           |
|   Stack                   | <- Function calls (grows down)
+---------------------------+
```

---

## ✅ Rule of Thumb:

* Use **stack** for small, temporary data.
* Use **heap** for large data or data whose lifetime must extend beyond a single function.