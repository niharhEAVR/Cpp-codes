## ✅ Your Program:

```cpp
#include<iostream>

int main()
{
    std::string fullName;

    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);  // 🔹 KEY LINE

    std::cout << "Your name is: " << fullName << std::endl;

    return 0;
}
```

---

## 🧠 Step-by-Step Explanation

| Line                                | What it does                                             |
| ----------------------------------- | -------------------------------------------------------- |
| `#include<iostream>`                | Includes input/output support like `cin` and `cout`.     |
| `std::string fullName;`             | Declares a string variable to store the name.            |
| `std::cout << ...`                  | Asks user to enter their full name.                      |
| `std::getline(std::cin, fullName);` | 📌 Reads **entire line of input**, including **spaces**. |
| `std::cout << "Your name is..."`    | Displays the name back.                                  |
| `return 0;`                         | Ends the `main()` function.                              |

---

## ❗ Why not use `cin >> fullName`?

Because:

```cpp
std::cin >> fullName;
```

* Only reads **up to the first space**.
* So `"John Doe"` becomes just `"John"`.

🔑 That’s why we use:

```cpp
std::getline(std::cin, fullName);
```

— it reads the **whole line**, including spaces.

---

## ✅ Is there a **better** way?

### ➤ For basic user input with spaces:

✅ `std::getline()` is **already the best and most standard** method.

---

### ➤ Advanced/Alternatives? (only if needed)

1. **Using `std::ws` to ignore leftover whitespaces:**

   * If using both `cin` and `getline()` together:

     ```cpp
     std::getline(std::cin >> std::ws, fullName);
     ```
   * Useful if `cin` left a newline (`\n`) in the buffer.

2. **Using `std::getline()` with `std::istringstream`**
   For splitting names into first/last, etc. But that's more advanced.
