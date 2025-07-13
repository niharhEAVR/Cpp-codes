### 🧠 **Template Type Parameters by Reference** in C++

When using templates in C++, you can pass type parameters **by value**, **by reference**, or **by const reference**. This controls **how the function interacts with the passed arguments**—whether it copies them or modifies them directly.

---

## ✅ What Does “Template Type Parameter by Reference” Mean?

It means you're **binding the template parameter `T` to a reference** — so that **no copy is made**, and you can **modify the original variable** if it's a non-const reference.

---

## 🧪 1. **Syntax and Example**

### 🔸 Pass by reference:

```cpp
template<typename T>
void update(T& val) {
    val += val;
}
```

```cpp
int main() {
    int x = 10;
    update(x); // T deduced as int
    std::cout << x; // Output: 20, because x was modified
}
```

* `T& val` means we're taking `val` **by reference**.
* `T` is deduced as `int`.
* So `T&` becomes `int&`.

---

## 📌 2. What Gets Deducted?

When you write `T& val`, the compiler:

* **Deducts the base type `T`**, then
* **Appends &** (reference) after deducing the type.

### Example:

```cpp
template <typename T>
void func(T& arg);

int x = 5;
func(x); // T is deduced as int → so arg becomes int&
```

If you do:

```cpp
const int x = 5;
func(x); // T is deduced as const int → so arg becomes const int&
```

---

## 🔒 3. Using **Const References** in Templates

To avoid copying but still **prevent modification**, use `const T&`:

```cpp
template <typename T>
void print(const T& data) {
    std::cout << data << "\n";
}
```

This works for:

* Big objects (avoid copies),
* Preventing accidental modification.

---

## ⚙️ 4. Practical Use Cases

| Type       | Behavior                                       | Example         |
| ---------- | ---------------------------------------------- | --------------- |
| `T`        | Passed by value (copy made)                    | `func(5)`       |
| `T&`       | Passed by reference (can be modified)          | `func(x)`       |
| `const T&` | Passed by const reference (read-only, no copy) | `func("hello")` |

---

## ⚠️ Be Careful: Type Deduction and References

### Example:

```cpp
template<typename T>
void show(T val); // pass by value

template<typename T>
void showRef(T& val); // pass by reference

int main() {
    int x = 10;
    show(x);     // T = int
    showRef(x);  // T = int
    showRef(10); // ❌ ERROR! Cannot bind non-const lvalue reference to rvalue
}
```

* You **can't pass literals (like `10`)** to a `T&` unless it's `const T&`.

---

## 🧵 Recap

| Form       | Description                           |
| ---------- | ------------------------------------- |
| `T`        | Type passed by value                  |
| `T&`       | Type passed by (modifiable) reference |
| `const T&` | Type passed by const reference        |