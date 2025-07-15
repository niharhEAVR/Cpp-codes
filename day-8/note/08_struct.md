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

This is a function that:

* Takes a `Point` as a **const reference** (`const Point&`)
* **Does not copy** the `Point` (saves performance)
* **Prevents accidental modification** (because it's `const`)

```cpp
void print_point(const Point &point)
```

* `point` is a **reference** to the original object.
* The function only **reads** data (safe, efficient).

Inside:

```cpp
std::cout << "Point [ x: " << point.x << ", y : " << point.y << "]" << std::endl;
```

It prints the `x` and `y` values from the passed-in `Point`.

---

### 🔹 3. `print_point(point1);`

This line **calls the function** and passes a `Point` object called `point1`.

But ⚠️ your code doesn’t show where `point1` was defined. So for this to compile and work correctly, you need:

```cpp
int main()
{
    Point point1{10.5, 20.2};
    print_point(point1);
}
```

Now this works as expected.

---

### 🔍 What is really happening in memory?

#### Given:

```cpp
Point point1{10.5, 20.2};
```

Memory layout:

| Variable | Type     | Value |
| -------- | -------- | ----- |
| point1.x | `double` | 10.5  |
| point1.y | `double` | 20.2  |

When passed to `print_point`, C++:

* Creates a **reference to `point1`**
* Passes that reference into the function
* Accesses `point.x` and `point.y` safely without copying

---

## ✅ Why use `const Point&`?

| Option                   | Pros                            | Cons                            |
| ------------------------ | ------------------------------- | ------------------------------- |
| `Point point` (by value) | Simple                          | Makes a full copy of the object |
| `Point& point`           | No copy                         | Allows modification (unsafe)    |
| `const Point& point` ✅   | No copy, no modification (best) | Safe and efficient              |

---

## 🧪 Output Example:

```cpp
Point point1{10.5, 20.2};
print_point(point1);
```

### Output:

```
Point [ x: 10.5, y : 20.2 ]
```

---

## ✅ Final Summary

* You defined a `struct` called `Point`.
* You created a function `print_point` that takes a **const reference** to avoid copying.
* You passed a `Point` object `point1` into the function.
* The function safely reads and prints its values.
