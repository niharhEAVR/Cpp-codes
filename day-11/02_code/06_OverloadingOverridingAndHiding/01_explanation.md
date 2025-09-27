### ✅ Explanation

#### 1. **Overriding**

* `Shape::draw()` is virtual.
* `Oval::draw()` overrides it.
* `Circle::draw()` overrides Oval’s `draw()`.
* Behavior is **runtime polymorphism**:

```cpp
Shape* shape_ptr = &circle1;
shape_ptr->draw(); // Calls Circle::draw() at runtime
```

---

#### 2. **Overloading**

* Functions with the **same name but different parameters** exist in the same scope:

```cpp
Shape::draw(int color_depth)
Oval::draw(int color_depth, std::string_view color)
```

* Which function is called depends on **parameters at compile time**:

```cpp
oval1.draw(32, "Blue");  // Calls draw(int,string)
shape_ptr->draw(24);     // Calls draw(int) via Shape pointer
```

> This is **compile-time binding**.

---

#### 3. **Hiding**

* When a derived class declares a function with the same name but **different parameters**, it **hides base class functions**:

```cpp
circle2.draw(16); // ❌ Error: Circle::draw() hides Shape::draw(int)
circle2.Oval::draw(16, "Green"); // Works: explicit access to hidden base function
```

* Even though `Shape` has `draw(int)`, it’s hidden because `Circle` has `draw()` with no parameters.

---

### ✅ Key points

| Concept     | Example in code                           | Binding          |
| ----------- | ----------------------------------------- | ---------------- |
| Overriding  | `Shape::draw() → Circle::draw()`          | Runtime (vtable) |
| Overloading | `draw(int)` vs `draw(int,string)`         | Compile-time     |
| Hiding      | `Circle::draw()` hides `Shape::draw(int)` | Compile-time     |

---
---
---


### Code snippet 1 (commented out)

```cpp
Shape* shape_ptr = new Circle(10,"Circle1");
shape_ptr->draw(45,"Red");  // ❌ Error
delete shape_ptr;
```

#### What happens:

1. `shape_ptr` is of type **`Shape*`** (base class pointer).

2. `Shape` has:

   ```cpp
   virtual void draw() const;
   virtual void draw(int color_depth) const;
   ```

   * **It does NOT have `draw(int, std::string)`**.

3. `Circle` inherits from `Oval`, which has:

   ```cpp
   virtual void draw(int color_depth, std::string_view color) const;
   ```

   * This **overload** is not present in `Shape`.

4. **Why it fails:**

   * Base class pointer can **only see functions declared in the base class**.
   * Even though the actual object is `Circle`, `Shape*` cannot see `draw(int,string)` because that function is **introduced in Oval**, not in Shape.

✅ This demonstrates **pointer type determines what functions are visible**.

* Overriding works because the base has the function, but **overloads introduced in derived classes are hidden to base class pointers**.

---

### Code snippet 2

```cpp
Oval* shape_ptr2 = new Circle(10, "Circle2");
shape_ptr2->draw(45, "Green"); // ✅ Works
delete shape_ptr2;
```

#### What happens:

1. Pointer type is **`Oval*`**.
2. `Oval` declares:

   ```cpp
   virtual void draw(int color_depth, std::string_view color) const;
   ```
3. The pointer **sees this function**, so you can call it.
4. Actual object is `Circle`, which inherits `Oval` → `draw(int,string)` is available.
5. ✅ Works fine. No error.

---

### ✅ What this demonstrates

1. **Base class pointer only sees base class members**

   * Functions introduced in derived classes are **not visible** to a pointer of the base class.

2. **Derived class pointer allows access to all functions declared in that class or its base classes**

3. **Overloading vs Overriding behavior**:

   * Overriding works for functions that exist in the base.
   * Overloaded functions **introduced in derived classes are hidden** from base class pointers.

4. **Polymorphism does not automatically expose new overloads**

   * Only works for **virtual functions that exist in the static type** of the pointer/reference.

---

### Visual analogy

| Pointer type | Functions visible                         | Can call `draw(int,string)`? |
| ------------ | ----------------------------------------- | ---------------------------- |
| `Shape*`     | `draw()`, `draw(int)`                     | ❌ No                         |
| `Oval*`      | `draw()`, `draw(int)`, `draw(int,string)` | ✅ Yes                        |
| `Circle*`    | All inherited + Circle’s functions        | ✅ Yes                        |

---

💡 **Takeaway:**

* If you want a **base class pointer to call a derived overload**, the function must **exist in the base class** (even if it’s virtual).
* Otherwise, you must use a pointer/reference of the type that **declares the function**.
