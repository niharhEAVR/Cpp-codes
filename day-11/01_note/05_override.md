## 1️⃣ What `override` does

* In C++, when a **derived class** wants to **replace a virtual function** of its base class, we say it “overrides” the function.
* The `override` keyword is a **safety feature** that tells the compiler:

> “This function is meant to override a virtual function from a base class.”

* If it **doesn’t actually override** (wrong name, wrong signature, or base function isn’t virtual), the compiler will **give an error**.

This helps catch bugs where you think you’re overriding a function, but you’re not.

---

## 2️⃣ Example

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() const {  // virtual function
        cout << "Drawing Shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() const override {  // override ensures correct overriding
        cout << "Drawing Circle" << endl;
    }
};
```

✅ Explanation:

* `Shape::draw()` is `virtual`.
* `Circle::draw()` uses `override`, so the compiler **checks that it correctly overrides** a base virtual function.
* Now, if you make a typo:

```cpp
void draw() override;   // missing const
```

* Compiler will throw an error because `Shape::draw()` is `const`, and your function signature doesn’t match.
* Without `override`, this would compile silently, but it **would not actually override** — a subtle bug.

---

## 3️⃣ Key points

1. `override` is **not required**, your program works without it.
2. **Best practice:** always use it for derived classes to avoid mistakes.
3. Only works with **virtual functions**.

---

## 4️⃣ Real-world effect

```cpp
Shape* s = new Circle();
s->draw();  // calls Circle::draw() because it’s virtual
```

* If `Circle::draw()` had a signature mismatch and no `override` was used, `Shape::draw()` would run instead.
* `override` would have caught this **at compile time**, saving you from a tricky bug.

---

✅ **Summary**

| Keyword  | Purpose                                                                  |
| -------- | ------------------------------------------------------------------------ |
| virtual  | Enables dynamic dispatch (polymorphism)                                  |
| override | Ensures derived function **correctly overrides** a base virtual function |
