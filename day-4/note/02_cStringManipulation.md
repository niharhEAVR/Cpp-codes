## 🔍 What is `std::strcmp()`?

### ✅ Signature:

```cpp
int strcmp(const char* lhs, const char* rhs);
```

### 🔸 Purpose:

It **compares two null-terminated C-strings** (arrays of characters ending in `\0`) **lexicographically** (i.e., dictionary order).

### 🔸 Return Values:

| Return Value     | Meaning                                               |
| ---------------- | ----------------------------------------------------- |
| `0`              | Strings are equal                                     |
| `< 0` (negative) | `lhs` < `rhs` (comes before in lexicographical order) |
| `> 0` (positive) | `lhs` > `rhs` (comes after in lexicographical order)  |

---

## 🔧 Code Breakdown & What Happens

```cpp
const char *string_data1{"Alabama"};
const char *string_data2{"Blabama"};
```

This sets up **string literals**. These are **read-only** C-strings.

```cpp
char string_data3[]{"Alabama"};
char string_data4[]{"Blabama"};
```

This declares **modifiable arrays** initialized with string literals. They work the same in comparison, but you can modify the content.

---

### ▶️ First comparison:

```cpp
std::strcmp("Alabama", "Blabama")
```

* `'A'` (65 in ASCII) is less than `'B'` (66), so:
* 🔁 Compares first character: `'A' < 'B'` → returns **negative value**

---

### ▶️ Second comparison:

```cpp
std::strcmp(string_data3, string_data4)
```

* Same characters as above.
* ✅ Returns **same result**, negative.

---

### ▶️ Third comparison:

```cpp
string_data1 = "Alabama";
string_data2 = "Alabamb";
std::strcmp("Alabama", "Alabamb")
```

* Matches: A-l-a-b-a-m
* At the **last character**:

  * `'a'` (97) vs `'b'` (98)
* `'a'` < `'b'` → returns **negative**

---

### ▶️ Fourth comparison:

```cpp
string_data1 = "Alacama";
string_data2 = "Alabama";
std::strcmp("Alacama", "Alabama")
```

* Matches: A-l-a
* Next:

  * `'c'` (99) vs `'b'` (98)
* `'c'` > `'b'` → returns **positive**

---

### ▶️ Fifth comparison:

```cpp
string_data1 = "India";
string_data2 = "France";
std::strcmp("India", "France")
```

* First characters: `'I'` (73) vs `'F'` (70)
* `'I'` > `'F'` → returns **positive**

---

### ▶️ Sixth comparison:

```cpp
string_data1 = "Kigali";
string_data2 = "Kigali";
std::strcmp("Kigali", "Kigali")
```

* All characters are equal → returns **0**

---

## 📌 Summary Table:

| Strings Compared       | Result | Why?                  |
| ---------------------- | ------ | --------------------- |
| "Alabama" vs "Blabama" | < 0    | `'A'` < `'B'`         |
| "Alabama" vs "Alabamb" | < 0    | `'a'` < `'b'` at end  |
| "Alacama" vs "Alabama" | > 0    | `'c'` > `'b'`         |
| "India" vs "France"    | > 0    | `'I'` > `'F'`         |
| "Kigali" vs "Kigali"   | == 0   | Strings are identical |

---

## 🚫 Note on Commented Code:

```cpp
// string_data3 = "Alabama"; // ❌ Invalid
```

* You cannot **assign** to a `char[]` after declaration — arrays can't be reassigned like pointers.

---
---

## ✅ `int strcmp(const char* lhs, const char* rhs);`

This is the **function signature** of `std::strcmp()` — it tells you:

* It returns an `int` (comparison result)
* It takes **two pointers to `const char`** (i.e., two C-strings)
* Both strings **must be null-terminated** (i.e., end with `'\0'`)

---

### 🧠 So yes — it **only works** with **normal null-terminated C-style strings**.

That means:

### ✅ These work:

```cpp
const char* a = "Hello";         // String literal — null-terminated
char b[] = "World";              // Array with null-terminator
std::strcmp(a, b);               // ✅ Valid
```

### ❌ These do **NOT** work:

```cpp
char arr[5] = {'H', 'e', 'l', 'l', 'o'}; // ❌ Not null-terminated!
std::strcmp(arr, "Hello");              // ❌ Undefined behavior!
```

Without `'\0'`, `std::strcmp()` will just **keep reading memory** until it *accidentally* finds a `\0`, which is dangerous and undefined behavior.

---

## 🔍 Why `const char*`?

Because `std::strcmp()` is **not supposed to modify** the input strings — just compare them. So:

* You can pass read-only string literals like `"India"`
* You can also pass modifiable arrays like `char name[] = "India";`

But the function promises **not to modify** them.

---

### ✅ Summary:

| Can you use `strcmp` with this?          | Works? | Reason                              |
| ---------------------------------------- | ------ | ----------------------------------- |
| `"Hello"` (string literal)               | ✅      | Null-terminated string literal      |
| `char s[] = "Hi";`                       | ✅      | Null-terminated character array     |
| `char s[5] = {'H', 'e', 'l', 'l', 'o'};` | ❌      | No null terminator!                 |
| `std::string name = "Hello";`            | ❌\*    | Not compatible directly (see below) |

> ⚠️ \*You can convert `std::string` to C-string using `.c_str()`:

```cpp
std::string s1 = "India";
std::string s2 = "France";
std::strcmp(s1.c_str(), s2.c_str());  // ✅
```


---
---
---


### 👀 The code:

```cpp
const char * const str { "Try not. Do, or do not. There is no try."};
char target = 'T';
const char *result = str;
size_t iterations{};

while ((result = std::strchr(result, target)) != nullptr) {
    std::cout << "Found '" << target
              << "' starting at '" << result << "'\n";
    ++result;
    ++iterations;
}
std::cout << "iterations : " << iterations << std::endl;
```

---

## 🔹 What are we trying to do?

We are trying to **find all the `'T'` letters** in the sentence:

```
"Try not. Do, or do not. There is no try."
```

And print:

* Where each `'T'` is
* How many times `'T'` was found

---

## 🔹 What is `std::strchr`?

It’s a function in C++ (from C) that:

* Takes a C-string (like `"Try not..."`)
* And a **character to search for** (like `'T'`)
* It **finds the first place** in the string where that character appears
* And gives you a **pointer to it**

---

### 🧠 Think of it like this:

Imagine the string is like a long street:

```
| T | r | y |   | n | o | t | . | D | o | , | ...
^
Start of string
```

You are looking for **`'T'`** in this street.

`std::strchr` walks from left to right, and when it finds `'T'`, it stops and gives you a pointer (like an address) to that `'T'`.

---

## 🔁 How the loop works:

```cpp
while ((result = std::strchr(result, target)) != nullptr)
```

* `result` is **where we start looking**
* At first, it starts at the **beginning of the string**
* Then we do:

```cpp
++result;
```

This means: **move 1 step forward**, so next time, we skip the `'T'` we just found and search again.

---

### 🪄 Step-by-step breakdown:

#### 🧩 First run:

* `result = strchr("Try not. Do, or do not. There is no try.", 'T')`
* Finds `'T'` at the very beginning
* Prints:

  ```
  Found 'T' starting at 'Try not. Do, or do not. There is no try.'
  ```
* Moves to next character with `++result`

#### 🧩 Second run:

* `result = strchr("ry not. Do, or do not. There is no try.", 'T')`
* Finds another `'T'` in `"There is no try."`
* Prints:

  ```
  Found 'T' starting at 'There is no try.'
  ```

#### 🧩 Third run:

* No more `'T'`, so `strchr` returns `nullptr`
* Loop ends.

---

## 🔚 Final Output:

```
Found 'T' starting at 'Try not. Do, or do not. There is no try.'
Found 'T' starting at 'There is no try.'
iterations : 2
```

---

## ✅ Final Thoughts

* `std::strchr` is just a way to find a character in a C-style string (`const char*`)
* Each time it finds `'T'`, you print it
* Then move forward so you can find the next one
* You count how many times this happens


---
---
---

> **"But `result` is declared as `const char*`, how can we change it?"**

Let’s **break it down simply**:

---

### 🧠 What does this mean?

```cpp
const char* result = str;
```

It means:

* `result` is a **pointer** to a **`const char`**
* You **can change where the pointer points**
* But you **cannot change the character** that it points to

---

### 📌 Think of it like this:

If `const char*` confuses you, just say:

> "I’m allowed to move the pointer, but I’m not allowed to modify the string."

So these are:

| Action                | Allowed? | Why?                        |
| --------------------- | -------- | --------------------------- |
| `result = something;` | ✅ Yes    | Reassigning the pointer     |
| `++result;`           | ✅ Yes    | Moving the pointer forward  |
| `*result = 'Z';`      | ❌ No     | Modifying a const character |

---

### 🔄 So in your loop:

```cpp
while ((result = std::strchr(result, target)) != nullptr)
```

You're doing:

* `result = ...` — ✅ **reassigning the pointer** to a new location
* NOT changing the string's contents — you're just **walking forward** through it

Even `++result;` is OK because you're just saying:

> “Move the pointer one step forward.”

---

### ✅ Visual Analogy:

Think of `const char*` like a bookmark in a **read-only book**:

* You **can move the bookmark** to any page
* But you **can’t write on the pages**

---

### 🤓 Bonus Tip:

If it were written as:

```cpp
char* const result = str;
```

That would mean:

* The **pointer can't move** (it's const)
* But the **characters it points to can be modified**

So the order of `const` matters!


---
---
---

## 🔸 The Code Again

```cpp
const char *str = "Try not. Do, or do not. There is no try.";
char target = 'T';
const char *result = nullptr;
size_t iterations = 0;

while ((result = std::strchr(str, target)) != nullptr)
{
    std::cout << "Found '" << target << "' starting at '" << result << "'\n";
    ++str;       // 🔴 This is the key bug
    ++iterations;
}
```

We are trying to **find 'T' in the string** repeatedly, but **incrementing `str` one character at a time** — and calling `strchr()` again and again on that updated `str`.

---

## 🔹 Step-by-Step Visualization

Let's **visualize the string as a line of boxes**, with character indexes:

```
Index:      0   1   2   3   4   5   6   7   8   9   10 ...
Content:   [T] [r] [y] [ ] [n] [o] [t] [.] [ ] [D] ...
Pointer:   ↑
         str starts here
```

### 🔸 Initial State

```cpp
str = "Try not. Do, or do not. There is no try."
target = 'T';
```

### ✅ 1st Iteration

* `str` points to `'T'`
* `std::strchr(str, 'T')` → finds `'T'` at index 0
* Output:
  `Found 'T' starting at 'Try not. Do, or do not. There is no try.'`
* Then: `++str` → Now `str` points to `'r'` (index 1)
* iterations = 1

---

### ✅ 2nd Iteration

Now we search again:

```
New str: "ry not. Do, or do not. There is no try."
         ↑ (starts at index 1)
```

* `std::strchr(str, 'T')` → Still finds `'T'`, but now it's at **"There is no try."**, index 28 in the original string.
* Output:
  `Found 'T' starting at 'There is no try.'`
* `++str` → now points to `'y'` (index 2)
* iterations = 2

---

### ⏩ Next Iterations

This keeps happening!

* `strchr(str, 'T')` keeps returning **same pointer** to that `'T'` in `"There"`, because you're only moving `str` 1 step each time.
* So, `strchr` still finds the same `'T'` in `"There"` again and again and again...
* It takes **25 times** before `str` moves **past** that `'T'` — then `strchr()` finally returns `nullptr`.

---

## 🔴 What’s the Bug?

You keep moving `str` like this:

```text
str → 'r'
str → 'y'
str → ' '
str → 'n'
...
```

But the `result` keeps pointing to:

```
"There is no try."
         ↑
        same 'T'
```

So you're finding the **same T again and again**, until `str` crosses it.

---

## ✅ Correct Version

The **fix** is to update `str` using `result + 1`, so you skip past the found `T` immediately:

```cpp
str = result + 1; // Go to next character after the found T
```

### Corrected Loop

```cpp
while ((result = std::strchr(str, target)) != nullptr)
{
    std::cout << "Found '" << target << "' starting at '" << result << "'\n";
    str = result + 1;
    ++iterations;
}
```

Now:

* 1st find: `'T'` at index 0
* 2nd find: `'T'` at index 28
* After that, no more `'T'` — loop ends correctly.

---

## 🧾 Final Output with Fixed Code:

```text
Found 'T' starting at 'Try not. Do, or do not. There is no try.'
Found 'T' starting at 'There is no try.'
iterations : 2
```

---

## ✅ Summary

| What You Did                   | What It Caused                         |
| ------------------------------ | -------------------------------------- |
| `++str;`                       | Moves 1 char forward each time         |
| Result → same `'T'` every time | Loop repeats 25 times unnecessarily    |
| **Fix**: `str = result + 1;`   | Skips to next char **after found `T`** |



---
---
---


## 🔸 The String

We'll use this string:

```cpp
"Try not. Do, or do not. There is no try."
```

Now, let's **highlight the two `T`s** in it (positions **0** and **28**):

```
Index:      0         10        20        30
           |          |         |         |
String:   [T][r][y][ ][n][o][t][.][ ][D][o][,][ ][o][r][ ][d][o][ ][n][o][t][.][ ][T][h][e][r][e][ ][i][s][ ][n][o][ ][t][r][y][.]
Index:     0                                    28
```

---

## 🧵 Let's Compare the Two Versions:

---

### ✅ ✅ **GOOD CODE (Correct Logic)**

```cpp
const char *const str = "Try not. Do, or do not. There is no try.";
const char *result = str;

while ((result = std::strchr(result, 'T')) != nullptr)
{
    std::cout << result;
    ++result;
}
```

### 🔍 What It Does

* `result` starts at the beginning: points to `'T'` at index 0.
* `std::strchr(result, 'T')` searches from **current result**.
* When `'T'` is found, we print it.
* Then we do `++result`, so **next search starts right after it.**

---

### 🔁 Visual Walkthrough

#### 🔸 Iteration 1:

```
result points to:      T r y ...
                       ↑
```

* Found `'T'` at index 0.
* `++result` moves it to `'r'`.

#### 🔸 Iteration 2:

```
result points to:        r y   n o t . . . T h e r e ...
                         ↑
```

* Found `'T'` at index 28.
* `++result` moves it to `'h'`.

#### 🔸 Iteration 3:

* `std::strchr(result, 'T')` = `nullptr`
* Loop ends ✅

### 🔢 Output:

```
Found 'T' starting at 'Try not. Do, or do not. There is no try.'
Found 'T' starting at 'There is no try.'
iterations: 2
```

✅ Efficient. Found each `'T'` **only once**.

---

## ❌❌ BAD CODE (Buggy Logic)

```cpp
const char *str = "Try not. Do, or do not. There is no try.";
const char *result = nullptr;

while ((result = std::strchr(str, 'T')) != nullptr)
{
    std::cout << result;
    ++str;
}
```

### 🔍 What It Does

* You always search **from `str`**, not from the last `result`.
* `str` starts at beginning. You move it **one step forward** each time (`++str`).
* But the `T` at index 28 takes **28 steps** to reach.

---

### 🔁 Visual Walkthrough

#### 🔸 Iteration 1:

```
str: "Try not. Do, or do not. There is no try."
      ↑
```

* Found `'T'` at index 0.
* `++str` → points to `'r'`

#### 🔸 Iteration 2:

```
str: "ry not. Do, or do not. There is no try."
       ↑
```

* `std::strchr(str, 'T')` now finds `'T'` at index 28 again
* `++str` → moves one character → `'y'`
* Repeat...
* **This continues 25 times** before `str` passes the `'T'` at index 28.

### 🔢 Output:

```
Found 'T' starting at 'Try not. Do, or do not. There is no try.'
Found 'T' starting at 'There is no try.'
Found 'T' starting at 'here is no try.'
...
(23 more times...)
iterations: 25
```

❌ Inefficient. Same `'T'` is printed again and again until you move past it.

---

## 🎯 So What's the Key Difference?

| Feature                   | ✅ GOOD Code                | ❌ BAD Code                   |
| ------------------------- | -------------------------- | ---------------------------- |
| What moves after match?   | `result = result + 1`      | `str = str + 1`              |
| Where search starts from? | `result` (from last match) | `str` (moves slowly forward) |
| Loop ends after how many? | 2 iterations               | 25 iterations                |
| Does it repeat same 'T'?  | ❌ No                       | ✅ Yes                        |

---

## ✅ The Fix

In the good version:

```cpp
result = std::strchr(result, 'T');
++result;
```

You're searching from where you left off.

In the bad version:

```cpp
result = std::strchr(str, 'T');
++str;
```

You're not moving forward fast enough — you keep re-finding the same match.


---
---
---




🎉 **YES! You nailed it!** That’s **exactly right** — and I'm genuinely glad it clicked now. Let's lock it in:

---

## ✅ Final Understanding:

### ❌ BAD CODE:

```cpp
result = std::strchr(str, 'T');
++str;
```

* `strchr(str, 'T')`: always searches from **`str`**.
* `result` just stores the match, but **search always restarts from `str`**.
* You’re not storing progress — you're just nudging `str` forward step by step.
* You’re telling it:
  *"Hey, start from here again, did you find 'T'? Cool. Now move me just one step ahead."*

---

### ✅ GOOD CODE:

```cpp
result = std::strchr(result, 'T');
++result;
```

* `strchr(result, 'T')`: always searches from **`result`**, which you keep updating.
* It’s like saying:
  *"I found the last 'T' here. Now skip past it and search from where I left off."*

✅ This avoids re-searching the same 'T'.

---

## 🔑 Key Phrase To Remember:

> **"In the good version, I keep searching from the last match. In the bad version, I keep restarting the search from a slowly moving start point."**




---
---


### ✅ Code:

```cpp
char input[] = "/home/user/hello.cpp";
char* output = std::strrchr(input, '/');
if (output)
    std::cout << output + 1 << std::endl;
```

---

## 🔍 What does `std::strrchr()` do?

* `std::strrchr(str, ch)`:

  * Finds the **last occurrence** of character `ch` **in the C-string `str`**
  * Returns a **pointer to that character**
  * Returns `nullptr` if not found

---

## 🧠 Visualize the Input String

Let's lay out the string and index it:

```
Index:     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18
Char:     [/] [h][o][m][e][/] [u][s][e][r][/] [h][e][l][l][o][.][c][p][p]
Pointer:   ↑                             ↑                   ↑
         1st '/'                    2nd '/'            3rd and last '/'
```

---

### 🔎 Step-by-Step Breakdown:

#### Line 1:

```cpp
char input[] = "/home/user/hello.cpp";
```

* A C-style string stored in an array (`input[]`)
* Content: `"/home/user/hello.cpp"`

#### Line 2:

```cpp
char *output = std::strrchr(input, '/');
```

* `std::strrchr(input, '/')` searches for the **last '/'**
* The last `'/'` is at index 10: just **before `'hello.cpp'`**
* So:

  ```cpp
  output → points to &input[10] = '/'
  ```

#### Line 3:

```cpp
std::cout << output + 1 << std::endl;
```

* `output + 1` → moves pointer to next character: `'h'`
* So the output is:

```
hello.cpp
```

✅ Success! You've extracted the filename.

---

## 💡 Real Use Case:

This trick is used **everywhere in file systems** when you want to **extract the filename** from a full path.
