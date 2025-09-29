## 🔹 1. Keywords vs contextual keywords in C++

In C++, some words are **true reserved keywords** (like `class`, `public`, `int`, `virtual`).
Others, like `override` and `final`, are **contextual keywords** introduced in **C++11**.

👉 What does that mean?

* They only have special meaning **in specific contexts** (inside class declarations, after function signatures).
* Outside those contexts, they can still be used as identifiers (variable names, function names).

---

## 🔹 2. Example: `override`

```cpp
class Animal {
public:
    virtual void sound() { cout << "Animal sound\n"; }
};

class Dog : public Animal {
public:
    void sound() override { cout << "Dog barks\n"; }  // ✅ override used correctly
};
```

Here, `override` is a contextual keyword → tells the compiler:

* “This function **must** override a virtual function from the base class.”

If you misspell it, the compiler will give an error.

But if you use `override` elsewhere:

```cpp
int override = 10;   // ✅ valid in C++
cout << override;
```

👉 This works, because here `override` is just a variable name.
It only gets special meaning when placed after a function declaration inside a class.

---

## 🔹 3. Example: `final`

```cpp
class Dog final {};   // ✅ "final" class

// ❌ Error: cannot inherit from final class
class Bulldog : public Dog {};
```

But again:

```cpp
int final = 42;  // ✅ valid variable name
cout << final;
```

So `final` is **not reserved everywhere**, only in class/function contexts.

---

## 🔹 4. Why not make them real keywords?

C++ is a huge language with **backward compatibility** in mind.

* If `final` and `override` were made *true reserved keywords*, then a lot of old codebases that already used `final` or `override` as variable names would suddenly break.
* By making them **contextual**, old code continues to compile, and new code can still use modern polymorphism features.

---

## 🔹 5. Summary

* `override` and `final` are **contextual keywords**, not fully reserved keywords.
* They have special meaning **only in certain places** (class declarations, after virtual function signatures).
* Outside of those places, you can still use them as normal identifiers (though not recommended for readability).
