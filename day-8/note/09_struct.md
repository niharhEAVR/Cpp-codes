## ✅ What is a `struct`?

A `struct` is a user-defined data type used to **group related variables** (and optionally functions) into a single unit.

### 🔹 Example:

```cpp
struct Dog {
    std::string name;
    int age;

    void bark() {
        std::cout << name << " says Woof!" << std::endl;
    }
};
```

You can create and use it like:

```cpp
Dog d1;
d1.name = "Fluffy";
d1.age = 3;
d1.bark();
```

---

## 🆚 Difference between `struct` and `class` in C++

In C++, **`struct` and `class` are nearly identical** — both can:

* Contain member **variables and functions**
* Have **constructors**, **destructors**, and **member functions**
* Use **inheritance**, **access specifiers**, etc.

But they differ in **only 2 main ways**:

| Feature                       | `struct` | `class`   |
| ----------------------------- | -------- | --------- |
| 🔒 Default Access Modifier    | `public` | `private` |
| 🔄 Default Inheritance Access | `public` | `private` |

---

### 📌 1. Default Access Modifier

```cpp
struct MyStruct {
    int x;  // public by default
};

class MyClass {
    int x;  // private by default
};
```

So:

```cpp
MyStruct s;
s.x = 10; // ✅ okay

MyClass c;
c.x = 10; // ❌ error: x is private by default
```

---

### 📌 2. Default Inheritance Mode

```cpp
struct BaseStruct {};
struct DerivedStruct : BaseStruct {}; // public inheritance

class BaseClass {};
class DerivedClass : BaseClass {}; // private inheritance
```

---

## ✅ When to Use `struct` vs `class`

| Use `struct` when...                 | Use `class` when...                      |
| ------------------------------------ | ---------------------------------------- |
| You're modeling **simple data**      | You're designing **complex behavior**    |
| You want everything to be **public** | You want **encapsulation** (data hiding) |
| It's like a C-style data container   | It’s a full object with logic & privacy  |

---

## 🔁 Example Comparison:

```cpp
// Struct version
struct Point {
    int x;
    int y;
    void print() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

// Class version
class Point {
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}
    void print() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};
```

---

## 🧠 Bonus: Can Struct Have Private Members?

Yes! You can **manually specify** access in `struct` too:

```cpp
struct Dog {
private:
    int age;
public:
    void set_age(int a) { age = a; }
};
```

But the default is still `public`.

---

## ✅ Final Summary

| Feature               | `struct`    | `class`         |
| --------------------- | ----------- | --------------- |
| Default access        | public      | private         |
| Default inheritance   | public      | private         |
| Can have methods?     | Yes         | Yes             |
| Can inherit?          | Yes         | Yes             |
| Can have constructor? | Yes         | Yes             |
| Use for               | Simple data | Full OOP models |

---
---
---

Let’s go step-by-step and understand **exactly what is happening** in:

```cpp
struct Point
{
    double x;
    double y;
};

void print_point(const Point &point)
{
    std::cout << "Point [ x: " << point.x << ", y : " << point.y << "]" << std::endl;
}

print_point(point1); // 👈 What is happening here?
```

---

## ✅ Step-by-Step Breakdown

### 🔹 1. `struct Point`

```cpp
struct Point {
    double x;
    double y;
};
```

* You’ve defined a `Point` structure with two data members:

  * `x` — x-coordinate
  * `y` — y-coordinate
* These are **public by default**, so they can be accessed directly.

This is just like:

```cpp
class Point {
public:
    double x;
    double y;
};
```

---

### 🔹 2. `void print_point(const Point &point)`

### i. `Point`

* `Point` is your `struct` type:

  ```cpp
  struct Point {
      double x;
      double y;
  };
  ```
* So `Point` is just a **custom data type** holding two doubles (`x` and `y`).


### ii. `const Point &point`

This means **“a reference to a constant Point object.”**

* **`&` (reference)**
  Instead of copying the entire `Point` into the function, we just pass a reference (an alias).

  * If `point1` is `Point {10, 55.5}`, then inside the function, `point` refers directly to `point1`.
  * No copy happens → **more efficient**.

* **`const` (constant)**
  Means the function **cannot modify** the `Point` object passed in.

  * So inside `print_point`, you can read `point.x` and `point.y`,
  * but you **cannot assign** new values like `point.x = 50;`.
  * This ensures **safety**: caller knows their object won’t be changed.

👉 So `const Point& point` is basically:

> “Give me a reference to your `Point` so I can look at it without making a copy, and I promise I won’t modify it.”


### iii. Why not just `Point point`?

If you wrote:

```cpp
void print_point(Point point);
```

* It would **make a copy** of the whole `Point` when calling the function.
* For small structs like `Point` (only 2 doubles), that’s not terrible.
* But for large objects (like `std::string`, `std::vector`), copying is **expensive**.
* That’s why C++ best practice is **pass by const reference**.


### iv. Why not `Point& point` (without const)?

```cpp
void print_point(Point& point);
```

* That would also avoid the copy, but now the function **can change the caller’s object**.
* Example:

  ```cpp
  void print_point(Point& point) {
      point.x = 999;  // modifies original
  }
  ```
* But since you only want to *print* the values, not modify them, you use `const`.


### ✅ In your code

```cpp
print_point(point1);
```

* `point1` is passed **by const reference** into the function.
* The function reads and prints its values.
* No copy, no modification.


🔑 **Summary**

* `const Point&` → efficient + safe way to pass objects.
* Function can only read, not modify.
* Avoids unnecessary copying.


---

### 🔹 3. `print_point(point1);`

This line **calls the function** and passes a `Point` object called `point1`.

```cpp
int main()
{
    Point point1{10.5, 20.2};
    print_point(point1);
}
```

Now this works as expected.

