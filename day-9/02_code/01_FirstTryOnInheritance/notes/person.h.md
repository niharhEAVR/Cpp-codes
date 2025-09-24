## 🔹 File Overview

This file defines a **class named `Person`**, which represents a person with a **first name** and **last name**. It also contains **getter and setter functions**, a **friend function** for printing, and some default values.

---

## 1. `#pragma once`

* This is a **header guard**.
* It tells the compiler: **“Include this file only once during compilation”**, even if multiple `#include "person.h"` statements are present in different files.
* Prevents **multiple definition errors**.

---

## 2. Includes

```cpp
#include <iostream>
#include <string>
```

* `#include <iostream>` → Needed for `std::ostream` (used in printing the object with `<<`).
* `#include <string>` → Needed for the `std::string` type.

---

## 3. Class Definition

```cpp
class Person
{
    friend std::ostream &operator<<(std::ostream &out, const Person &person);
```

* Declares the **`Person` class**.
* Inside it, we declare a **friend function**:

  ```cpp
  friend std::ostream &operator<<(std::ostream &out, const Person &person);
  ```

  * This allows us to use `std::cout << person;` directly.
  * Since it’s a `friend`, it can access private members (`first_name`, `last_name`) even though they’re private.

---

## 4. Public Section

```cpp
public:
    Person() = default;
    Person(std::string &first_name_param, std::string &last_name_param);
```

* **`public:`** → These members are accessible from outside the class.
* `Person() = default;`

  * Default constructor.
  * Compiler will generate one that initializes members with their default values.
* `Person(std::string &first_name_param, std::string &last_name_param);`

  * Parameterized constructor (implementation not shown here, probably in `person.cpp`).
  * Lets you create a `Person` with specific first and last names.

---

## 5. Getters

```cpp
std::string get_first_name() const
{
    return first_name;
}

std::string get_last_name() const
{
    return last_name;
}
```

* Return the **first name** and **last name**.
* Marked `const`, meaning they don’t modify the object.
* Return by value (`std::string`), which makes a copy.



### `const` (after the function name)

This is **very important**.
It means the function **will not modify the object** on which it is called.

Example:

```cpp
const Person p;          // a const object (cannot be modified)
std::cout << p.get_first_name(); // ✅ works because getter is const
```

If `const` was missing, you **couldn’t call this function** on a const object.


---

## 6. Setters

```cpp
void set_first_name(std::string_view fn)
{
    first_name = fn;
}
void set_last_name(std::string_view ln)
{
    last_name = ln;
}
```

* Allow you to **change** the first and last names after creating the object.
* Use `std::string_view` (more efficient than `std::string` in many cases).

  * It avoids copying unless necessary.

---

## 7. Private Section

```cpp
private:
    std::string first_name{"Mysterious"};
    std::string last_name{"Person"};
};
```

* **Private:** Only accessible inside the class (and friends).
* Default values:

  * `first_name` → `"Mysterious"`
  * `last_name` → `"Person"`
* So, if you create a `Person` without setting values, it defaults to `"Mysterious Person"`.

---

## 🔹 Example Usage

```cpp
#include "person.h"

int main()
{
    Person p1; // Uses default constructor
    std::cout << p1 << std::endl; // Prints: Mysterious Person

    std::string fn = "Harsh";
    std::string ln = "Sharma";
    Person p2(fn, ln); // Uses parameterized constructor
    std::cout << p2 << std::endl; // Prints: Harsh Sharma

    p2.set_first_name("Rohit");
    std::cout << p2.get_first_name(); // Prints: Rohit
}
```

---

✅ **In summary**:

* `#pragma once` → header guard
* Class has **data members** (`first_name`, `last_name`)
* Provides **getters & setters**
* Has **default + parameterized constructors**
* Has a **friend operator<<** for easy printing

---
---
---

```cpp
friend std::ostream &operator<<(std::ostream &out, const Person &person);
```

---

## 🔹 Step 1: `friend`

* Tells the compiler: *“This function is not part of the class, but it’s allowed to access private members of this class.”*
* So even though `first_name` and `last_name` are private, this function can still use them.

---

## 🔹 Step 2: `std::ostream &`

* This is the **return type**.
* `std::ostream` is the type of output streams (like `std::cout`).
* Returning a **reference (`&`)** means we can chain outputs:

  ```cpp
  std::cout << p1 << p2; // works because operator<< returns ostream&
  ```

---

## 🔹 Step 3: `operator<<`

* This is the function’s **name**.
* In C++, `operatorX` means you are defining how operator `X` works for your class.
* Here, it’s defining how the **insertion operator `<<`** behaves for `Person`.

---

## 🔹 Step 4: `(std::ostream &out, const Person &person)`

* These are the **parameters**:

  1. `std::ostream &out` → the output stream object (like `std::cout`). Passed by reference.
  2. `const Person &person` → the person we want to print. Passed by const reference so it doesn’t copy and doesn’t modify.

---

## 🔹 Step 5: Putting it together

This line means:

👉 *“I’m declaring a function named `operator<<` that takes an `ostream` (like cout) and a `Person`, and returns that same ostream so we can chain outputs. This function is a **friend** of `Person`, so it can look inside `Person`’s private data.”*

---

## 🔹 Example Implementation

In `person.cpp` you’d write:

```cpp
std::ostream &operator<<(std::ostream &out, const Person &person) {
    out << person.first_name << " " << person.last_name;
    return out;
}
```

Now you can do:

```cpp
Person p;
std::cout << p;   // prints: Mysterious Person
```

---

✅ So the whole line is just a **declaration** inside the class that says:
“Yo compiler, there’s going to be an `operator<<` function outside the class. Treat it as my friend so it can access my private stuff.”
