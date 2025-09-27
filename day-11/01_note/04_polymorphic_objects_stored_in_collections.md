Let's explain **“polymorphic objects stored in collections”** using **the code**, step by step:

---

## 1️⃣ What is happening in your first example (array of base objects)

```cpp
Shape shapes1[]{circle1, oval1, circle2, oval2, circle3, oval3};
```

* You are trying to **store Circle and Oval objects in an array of `Shape` objects**.
* **Problem:** This is **object slicing**.

**Why?**

* `Shape` is the base class.
* `Circle` and `Oval` are derived classes.
* When you copy a `Circle` or `Oval` into a `Shape` object **by value**, the **derived part is lost**.
* Only the `Shape` part (members inherited from Shape) is stored in the array.

**Evidence in your loop:**

```cpp
for (Shape &s : shapes1) {
    s.draw(); // only Shape::draw() is called
}
```

* Even though `draw()` is virtual, the array actually contains **pure `Shape` objects**, so dynamic dispatch cannot call the derived class version.
* This is classic **slicing**.

---

## 2️⃣ Why you can’t have “array of references”

```cpp
// const Shape &shapes2[]{circle1, oval1, ...}; // ❌ compiler error
```

* References must be **bound at initialization** and **cannot be reseated**.
* Arrays store **actual objects**, and references can’t be reassigned to new elements.
* That’s why **C++ doesn’t allow arrays of references**.

---

## 3️⃣ Using raw pointers (`Shape* shapes3[]`)

```cpp
Shape *shapes3[]{&circle1, &oval1, &circle2, &oval2, &circle3, &oval3};
```

* Now the array stores **pointers to base class**.
* Each pointer points to a **real object of the derived class**.

### Key points:

1. `sizeof(*shape_ptr)` → always returns **size of `Shape`**, because the compiler only sees the **static type** (the pointer is `Shape*`).

2. `shape_ptr->draw();` → **calls the correct derived class’s `draw()`**, because `draw()` is **virtual**, so runtime uses the **vtable** (dynamic dispatch).

✅ No slicing occurs because the pointers are pointing to the original derived objects, not copying them.

---

## 4️⃣ Using smart pointers (`std::shared_ptr<Shape>`)

```cpp
std::shared_ptr<Shape> shapes4[]{
    std::make_shared<Circle>(12.2, "Circle4"),
    std::make_shared<Oval>(10.0, 20.0, "Oval4")
};
```

* Works exactly like raw pointers but **manages memory automatically**.
* Each element owns a derived object on the heap.
* `s->draw();` calls the correct derived function.

**Advantage over raw pointers:** no memory leaks, safer lifetime management.

---

## ✅ Summary with your code

| Method                                  | Slicing?      | Polymorphism works? | Notes                                            |
| --------------------------------------- | ------------- | ------------------- | ------------------------------------------------ |
| `Shape shapes1[]{circle1, oval1...}`    | ✅ Yes         | ❌ No                | Derived parts are lost, only base `Shape` copied |
| Array of references                     | ❌ Not allowed | ❌ N/A               | References cannot be stored in arrays            |
| `Shape* shapes3[]{&circle1, &oval1...}` | ❌ No          | ✅ Yes               | Pointers allow polymorphism using vtable         |
| `std::shared_ptr<Shape>`                | ❌ No          | ✅ Yes               | Like pointers, but memory-managed                |

---

💡 **Big idea:**

> If you want a collection of polymorphic objects that behave correctly, **store pointers (raw or smart)** to the base class, never store the objects by value.
