### 🧠 Summary of the Variables:

```cpp
short int var1 {10};   // 2 bytes
short int var2 {20};   // 2 bytes
char var3 {40};        // 1 byte
char var4 {50};        // 1 byte
```

---

### 📌 Step 1: `sizeof(...)` Results

```cpp
sizeof(var1) → 2 bytes  
sizeof(var3) → 1 byte
```

That’s expected.

---

### 💥 Step 2: What Happens in These Expressions?

```cpp
auto result1 = var1 + var2;
auto result2 = var3 + var4;
```

These **look like small-type arithmetic**, but **C++ does something important here called *integer promotion***.

---

## 🚀 What Is Integer Promotion?

Whenever you do arithmetic with types **smaller than `int`** (like `char`, `short`), C++ **automatically promotes them to `int`** before performing the operation.

### 📣 Why?

* To match CPU register size (typically 32 bits)
* To avoid data loss and make operations efficient

---

### 🔍 Detailed Explanation

#### `result1 = var1 + var2`

* `var1` and `var2` are `short` (2 bytes)
* C++ promotes them to `int` (4 bytes) during `+`
* So the result is of type `int`
* Hence: `sizeof(result1)` is `4`

#### `result2 = var3 + var4`

* `var3` and `var4` are `char` (1 byte)
* Both get promoted to `int` during `+`
* So `result2` is also `int`
* Hence: `sizeof(result2)` is `4`

---

### ✅ Output Explanation

```cpp
size of var1 : 2
size of var2 : 2
size of var3 : 1
size of var4 : 1
size of result1 : 4
size of result2 : 4
```

---

### 🧪 Want to see actual types?

Add this to your code (C++17+):

```cpp
std::cout << "type of result1: " << typeid(result1).name() << std::endl;
std::cout << "type of result2: " << typeid(result2).name() << std::endl;
```

Usually prints something like:
`i` → means `int` (compiler mangled name)
