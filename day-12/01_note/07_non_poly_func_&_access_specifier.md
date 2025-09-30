This new code is very similar to your earlier one, but here the comments say **“Static binding / non-poly func”**, so let’s carefully walk through what’s happening.

---

# 🔹 Step 1: Clarify Terms

* **Polymorphic function (runtime binding)** → needs `virtual`.
  The function call is resolved **at runtime**, depending on the actual object type.
* **Non-polymorphic function (static binding)** → normal function (no `virtual`).
  The function call is resolved **at compile time**, depending only on the declared type (the static type).

👉 In your example, `draw()` and `func()` are **not declared `virtual`**, so they are **non-polymorphic functions**. That means **static binding** always happens.

---

# 🔹 Step 2: Walk through your example

### **Case 1: Base pointer (`shared_ptr<Shape>`)**

```cpp
std::shared_ptr<Shape> shape0 = std::make_shared<Ellipse>(1, 5, "ellipse0");
shape0->draw();  // Static binding -> Shape::draw()
shape0->func();  // ❌ Error: func is private in Shape
```

* Even though the actual object is `Ellipse`, the pointer type is `Shape*`.
* Since `draw()` is **not virtual**, the compiler binds it at compile time → `Shape::draw()` is called.
* `func()` is **private in Shape**, so a `Shape*` cannot call it.

👉 Access specifier is checked on the **static type** (`Shape` here).

---

### **Case 2: Direct derived object**

```cpp
Ellipse ellipse1(1, 6, "ellipse1");
ellipse1.func();  // ✅ Works (public in Ellipse)
ellipse1.draw();  // ❌ Error (draw is private in Ellipse)
```

* Type is `Ellipse`.
* Compiler looks at `Ellipse`’s access specifiers:

  * `func()` is `public` in `Ellipse` → works.
  * `draw()` is `private` in `Ellipse` → error.

👉 Here the access is decided by `Ellipse` class, not `Shape`.

---

### **Case 3: Object slicing**

```cpp
Shape shape3 = Ellipse(2, 3, "ellipse3");
shape3.draw();  // Shape::draw() called
shape3.func();  // ❌ Error: private in Shape
```

* Because of **slicing**, only the `Shape` part of `Ellipse` is copied.
* Now it’s just a `Shape` object → so `Shape::draw()` is called.
* `func()` is private in `Shape` → error.

👉 This shows that polymorphism is lost when slicing.

---

# 🔹 Step 3: Access Specifiers in This Context

* **Access specifiers (`public`, `protected`, `private`)** are checked at **compile time** based on the **declared type** (not the actual object).
* If a base pointer/reference is used → compiler checks the **base class access specifier**.
* If a derived object is used → compiler checks the **derived class access specifier**.
* With slicing → only base class exists, so only base class access specifiers matter.

---

# ✅ Big Picture

| Case                                 | Type of Object | Function type        | Binding                  | Which Access Rules? |
| ------------------------------------ | -------------- | -------------------- | ------------------------ | ------------------- |
| Base pointer (`Shape*`) to `Ellipse` | `Shape*`       | Non-virtual → static | **Shape** access rules   |                     |
| Direct derived object (`Ellipse`)    | `Ellipse`      | Non-virtual → static | **Ellipse** access rules |                     |
| Sliced object (`Shape = Ellipse`)    | `Shape`        | Non-virtual → static | **Shape** access rules   |                     |

---

👉 So when your comment says **“non poly func / static binding”**, it means:

* The function isn’t virtual → no runtime dispatch.
* Compiler decides which function to call **based on the declared type** and enforces access specifiers from that type.
