## 🧠 What is a **Function** in C++?

A **function** is a block of code that performs a specific task.
You write it **once**, and you can **reuse** it multiple times.

---

### 🔹 Your Code Example:

```cpp
int addNumbers(int a, int b);  // Function declaration (prototype)

int main()
{
    std::cout << "result: " << addNumbers(3,4) << std::endl;   
    return 0;
}

int addNumbers(int a, int b)   // Function definition
{
    return a + b;
}
```

---

## 🧩 Explanation of Each Part:

| Part                            | Meaning                                                                                                                                                            |
| ------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| `int addNumbers(int a, int b);` | 👉 **Function Declaration** (also called prototype) <br> Says: "Hey compiler, a function named `addNumbers` exists, and it takes two `int`s and returns an `int`." |
| `int addNumbers(...) {}`        | 👉 **Function Definition** – actual code to do the task                                                                                                            |
| `addNumbers(3, 4)`              | 👉 **Function Call** – you're using the function here                                                                                                              |

---

## ✅ **Why declare a function before `main()`?**

Because **C++ reads top to bottom**.
If you use a function *before* defining it, the compiler must know it **exists** and **what it returns**.

So we give it a **declaration** or **prototype** to avoid a compile-time error.

---

## 💡 Benefits of Functions:

| Benefit                            | Explanation                         |
| ---------------------------------- | ----------------------------------- |
| ✅ **Code Reuse**                   | Write once, use many times.         |
| ✅ **Improves Readability**         | Breaks code into smaller chunks.    |
| ✅ **Makes Debugging Easier**       | Isolate issues in small blocks.     |
| ✅ **Supports Modular Programming** | Each function does a specific task. |

---

## ⚠️ Drawbacks (Cons):

| Drawback                                   | Explanation                                                   |
| ------------------------------------------ | ------------------------------------------------------------- |
| ❌ **Function call has overhead**           | Slight performance cost due to stack operations (very minor). |
| ❌ **Too many small functions = confusion** | If not named properly, can make code messy.                   |
| ❌ **Scope issues**                         | Variables in functions are local unless passed or returned.   |
