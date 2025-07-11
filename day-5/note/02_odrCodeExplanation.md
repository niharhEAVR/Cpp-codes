## 🔴 What's Going Wrong?

You're getting **two errors**:

### 1️⃣ **Multiple definition of `main`**

> ❌ You have a `main()` function in **both `file1.cpp` and `file2.cpp`**.
> ✅ C++ allows only **one `main()` function** in your whole program.

---

### 2️⃣ **Multiple definition of `count`**

> ❌ You defined `int count = 10;` inside **`header.h`**.
> That header is being included in **both `file1.cpp` and `file2.cpp`**, so `count` is getting defined **twice**.

This breaks the **One Definition Rule**.

---

## ✅ Correct Way to Structure It

---

### 🔷 Step 1: **`header.h`**

✅ Only declare `count` here, do **not define it**.

```cpp
// header.h
#pragma once  // or use include guards
extern int count;  // declaration only
void sayHello();   // function declaration (optional)
```

---

### 🔷 Step 2: **`file1.cpp`**

✅ Define the variable and optional function

```cpp
#include <iostream>
#include "header.h"

int count = 10;  // ✅ Only define once

void sayHello() {
    std::cout << "Hello from file1!" << std::endl;
}
```

---

### 🔷 Step 3: **`file2.cpp`**

✅ This is the only file that contains `main()`

```cpp
#include <iostream>
#include "header.h"

int main() {
    std::cout << "Value of count = " << count << std::endl;
    sayHello();
    return 0;
}
```

---

## ✅ Now Compile Both Files Together

```bash
g++ file1.cpp file2.cpp -o myprogram
```

Run it:

```bash
./myprogram
```

### ✅ Output:

```
Value of count = 10
Hello from file1!
```

---

## ✅ Summary Fixes

| Issue                           | Fix                                            |
| ------------------------------- | ---------------------------------------------- |
| `main()` in both `.cpp` files   | ❌ Not allowed → ✅ Keep `main()` in only 1 file |
| `int count = 10;` in `header.h` | ❌ Not allowed → ✅ Use `extern int count;` only |
| Include `header.h` everywhere   | ✅ Allowed, if it contains only declarations    |


---
---
---


## 🔷 What is ODR (One Definition Rule) in C++?

### ✅ Definition (simple words):

**In a C++ program, you are allowed to "declare" things many times, but you can "define" them only once.**

> ⚠️ If you define something more than once, you break the **One Definition Rule (ODR)**.

---

## 🔸 Declaration vs Definition (important)

| Term            | Meaning                                         | Example         |
| --------------- | ----------------------------------------------- | --------------- |
| **Declaration** | Saying "this thing exists somewhere"            | `extern int x;` |
| **Definition**  | Actually creating it (reserving memory or code) | `int x = 5;`    |

---

## ✅ Real-World Analogy

### Imagine this is your situation:

You’re writing a **company report** with **two team members**.

* One writes **Section A**.
* One writes **Section B**.

---

### 🔸 What is a Header File?

Think of a **header file** like a **common instruction sheet** both people read.
It tells them:

* What topics to write about
* What definitions will be included
* What to expect (but not the actual full content)

> 🔁 You can give both people this instruction sheet. But it shouldn’t **contain actual full content**, or both will write the same thing → **duplicate** → 📛 problem.

---

### 🔸 What Happens if Both Teams Define the Same Section?

* One person defines “Company Goals” in their section.
* The other person defines the exact same “Company Goals” again.

❌ Now the final document has **two copies** of the same section → confusion.

That’s an **ODR violation** in programming.

---

## ✅ Back to Code Example

### 🔹 Header File (like the instruction sheet)

```cpp
// header.h
extern int count;       // Just says: "count exists"
void sayHello();        // Just says: "sayHello exists"
```

### 🔹 file1.cpp (writes the actual content)

```cpp
#include "header.h"

int count = 10;         // Real definition (creates memory)
void sayHello() {
    std::cout << "Hi\n";
}
```

### 🔹 file2.cpp (uses it)

```cpp
#include "header.h"

int main() {
    std::cout << count << std::endl;
    sayHello();
}
```

✅ This works. You’ve followed **ODR**:

* `count` is defined only once (in `file1.cpp`)
* Declared (shared info) in `header.h`

---

## ❌ What if You Break the ODR?

If you **define `count = 10` in both files**, the compiler says:

> "Hey! You told me twice about the same variable. I don’t know which one to keep."

That’s the **One Definition Rule**:
👉 **Only ONE real definition allowed** for each variable, function, or class in the whole program.

---

## ✅ Simple Rules to Remember ODR

| Rule                         | Explanation                                              |
| ---------------------------- | -------------------------------------------------------- |
| Declare as much as you want  | Like saying “this thing exists”                          |
| Define only once             | Like giving the full info or code                        |
| Use `extern` for variables   | To declare, not define                                   |
| Use headers for declarations | Never put real data (like `int x = 5`) inside `.h` files |
