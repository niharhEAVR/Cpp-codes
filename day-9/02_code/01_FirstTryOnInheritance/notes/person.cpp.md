# 🔹 Relationship between `person.h` and `person.cpp`

* `person.h` → contains the **declarations** (what exists).
* `person.cpp` → contains the **definitions** (how it works).

So the `.h` is like a **blueprint**, `.cpp` is the **construction**.

---

# 🔹 Line by Line Breakdown

```cpp
#include "person.h"
```

* Includes the header file so this `.cpp` file knows the class definition.
* Without this, the compiler wouldn’t know what `Person` is.

---

```cpp
Person::Person(){
}
```

* This is the **default constructor** definition.
* `Person::Person` means “This is the constructor of the `Person` class.”
* Currently it does nothing explicitly because default values (`"Mysterious"`, `"Person"`) are already set in the header file.

---

```cpp
Person::Person(std::string& first_name_param, std::string& last_name_param)
    : first_name(first_name_param), last_name(last_name_param)
{
}
```

* This is the **parameterized constructor**.
* It takes two `std::string` references (`first_name_param`, `last_name_param`).
* Uses a **member initializer list**:

  ```cpp
  : first_name(first_name_param), last_name(last_name_param)
  ```

  which means: assign these parameters directly to the private members.
* Example usage:

  ```cpp
  std::string fn = "Harsh";
  std::string ln = "Sharma";
  Person p(fn, ln); // initializes first_name="Harsh", last_name="Sharma"
  ```

---

```cpp
std::ostream& operator<<(std::ostream& out , const Person& person){
    out << "Person [" << person.first_name << " " << person.last_name << "]";
    return out;
}
```

* This is the **definition** of the `friend operator<<` we declared in the header.
* It lets us print the `Person` object using `std::cout`.
* Example:

  ```cpp
  Person p(fn, ln);
  std::cout << p;
  ```

  Output:

  ```
  Person [Harsh Sharma]
  ```

---

```cpp
Person::~Person()
{
}
```

* This is the **destructor** of the `Person` class.
* It runs automatically when a `Person` object goes out of scope or is deleted.
* Right now it’s **empty** because `std::string` members automatically clean themselves up (RAII).
* If your class had raw pointers or resources, you’d release them here.

---

# 🔹 Summary

So `person.cpp` is:

1. Giving actual **definitions** of the functions declared in `person.h`.
2. Implements:

   * Default constructor
   * Parameterized constructor
   * `operator<<` for printing
   * Destructor

---

⚡ In short:

* `person.h` = **what the class looks like** (the interface).
* `person.cpp` = **how the class actually works** (the implementation).

---
---
---

```cpp
std::ostream& operator<<(std::ostream& out , const Person& person){
    out << "Person [" << person.first_name << " " << person.last_name << "]";
    return out;
}
```

and break it down piece by piece.

---

## 🔹 Function Signature

```cpp
std::ostream& operator<<(std::ostream& out , const Person& person)
```

1. **`std::ostream&` (return type)**

   * This means the function returns a reference to an output stream (like `std::cout`).
   * Returning a reference lets us chain outputs:

     ```cpp
     std::cout << p1 << p2 << p3;
     ```

2. **`operator<<` (function name)**

   * This is **operator overloading**.
   * We are defining how the `<<` operator works when used with a `Person` object.
   * Normally `<<` means "shift bits left," but here we redefine it to mean "insert into output stream."

3. **`(std::ostream& out , const Person& person)` (parameters)**

   * `std::ostream& out`: the output stream (e.g., `std::cout`, or a file stream). Passed by reference.
   * `const Person& person`: the `Person` object to print. Passed as const reference (so no copying, and the function won’t modify it).

---

## 🔹 Function Body

```cpp
out << "Person [" << person.first_name << " " << person.last_name << "]";
```

* This line **inserts text into the output stream**.
* Step by step:

  1. `"Person ["` → literal text goes into the stream.
  2. `person.first_name` → inserts the private member `first_name`.
  3. `" "` → inserts a space.
  4. `person.last_name` → inserts the private member `last_name`.
  5. `"]"` → closes the bracket.

So if `first_name = "Harsh"` and `last_name = "Sharma"`, the stream will now contain:

```
Person [Harsh Sharma]
```

---

## 🔹 Return Statement

```cpp
return out;
```

* Returns the same stream we wrote to.
* This is what allows chaining like:

  ```cpp
  std::cout << p1 << p2;
  ```

Without returning `out`, you could only do `std::cout << p1;` once.

---

## 🔹 In Plain English

This whole function means:

👉 *“Whenever someone uses `<<` with a `Person`, output the text `Person [first_name last_name]` into the stream, and give back the stream so we can keep printing more stuff.”*

---

## 🔹 Example

```cpp
Person p("Harsh", "Sharma");
std::cout << p;
```

Output:

```
Person [Harsh Sharma]
```
