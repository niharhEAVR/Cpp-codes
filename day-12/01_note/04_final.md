# 🔹 1. What is `final` in general?

The `final` keyword in C++ is used to **prevent further overriding or inheritance**.
It can be applied in two places:

1. **To a class** → prevents further inheritance.
2. **To a virtual function** → prevents that function from being overridden in derived classes.

---

# 🔹 2. `final` with classes

```cpp
class Animal {
public:
    virtual void sound() { cout << "Animal sound\n"; }
};

class Dog final : public Animal {   // ✅ final class
public:
    void sound() override { cout << "Dog barks\n"; }
};

// ❌ Error: Cannot inherit from a final class
class Bulldog : public Dog {
public:
    void sound() override { cout << "Bulldog barks loudly\n"; }
};
```

👉 Here, `Dog` is marked `final`, so **no other class can inherit from it**.

---

# 🔹 3. `final` with virtual functions (in polymorphism)

```cpp
class Animal {
public:
    virtual void sound() { cout << "Animal sound\n"; }
};

class Dog : public Animal {
public:
    void sound() final override { cout << "Dog barks\n"; }
};

// ❌ Error: cannot override a final function
class Bulldog : public Dog {
public:
    void sound() override { cout << "Bulldog barks loudly\n"; }
};
```

👉 Here, `Dog::sound()` is marked `final`.
So even though `sound()` is virtual, **Bulldog cannot override it anymore**.

---

# 🔹 4. Why do we need `final` in polymorphism?

* **Design choice**: Sometimes you want to allow polymorphism **up to a certain level**, but stop further overriding to ensure stability.
* **Performance optimization**: Marking a function `final` can let the compiler perform better optimizations (since it knows no other class can override it).
* **Error prevention**: Prevents accidental overriding of functions that should remain fixed.

---

# 🔹 5. Comparison: `virtual`, `override`, `final`

| Keyword    | Meaning                                                                          |
| ---------- | -------------------------------------------------------------------------------- |
| `virtual`  | Function can be overridden in derived classes                                    |
| `override` | Explicitly says "this function overrides a base class virtual function"          |
| `final`    | Prevents further overriding (for functions) or further inheritance (for classes) |

---

# 🔹 6. Real-world analogy

Imagine you have a **base class Vehicle**.

* You allow subclasses like `Car`, `Bike`.
* But if you define a specific class `TeslaCar` (final), you don’t want others to modify its behavior further → so you mark it as `final`.

Or if you design a `brake()` function in `Car` that must always work in a particular way, you mark it as `final` to stop derived classes from changing it.

---

✅ **In summary**

* `final` on a **class** → stops inheritance.
* `final` on a **virtual function** → stops overriding.
* It’s mainly used in **polymorphism** to control how far inheritance and overriding can go.
