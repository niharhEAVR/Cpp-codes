* **Array notation** → `p_scores[i]`
* **Pointer arithmetic** → `*(p_scores + i)`

## ✅ Example Code

```cpp
#include <iostream>

int main() {
    size_t size{5}; // Let's say the array has 5 elements

    // Dynamically allocate an array of size '5'
    int* p_scores = new int[size];

    // Assign values using array notation
    for (size_t i{}; i < size; ++i) {
        p_scores[i] = (i + 1) * 10; // Values will be: 10, 20, 30, 40, 50
    }

    // Print values using both array notation and pointer arithmetic
    for (size_t i{}; i < size; ++i) {
        std::cout << "value : " << p_scores[i]
                  << " : " << *(p_scores + i) << std::endl;
    }

    // Free the dynamically allocated memory
    delete[] p_scores;
    p_scores = nullptr;

    return 0;
}
```

---

## 🧠 Output:

```
value : 10 : 10
value : 20 : 20
value : 30 : 30
value : 40 : 40
value : 50 : 50
```

---

## 🧠 Explanation:

### 💡 `p_scores[i]` – Array Notation

This is how we **normally access elements**:

```cpp
p_scores[2] // gives the 3rd element (value 30)
```

### 💡 `*(p_scores + i)` – Pointer Arithmetic

* `p_scores` is a pointer to the first element.
* `p_scores + i` moves the pointer forward `i` elements.
* `*` dereferences it to get the actual value.

So:

| Expression        | Meaning                         |
| ----------------- | ------------------------------- |
| `p_scores[i]`     | value at index `i`              |
| `*(p_scores + i)` | value at address `p_scores + i` |

They are 100% equivalent.

---

## 🔁 Inside the loop:

```cpp
for (size_t i{}; i < size; ++i)
```

This loop:

* Starts `i` at `0`
* Goes up to `size - 1` (i.e., `0 → 4`)
* Prints each element **twice**, using both access methods

---

## 🧼 Final Notes:

* `size_t` is the **preferred type for array sizes/indexes** (unsigned).
* `delete[]` is used to safely release heap memory.
* `p_scores = nullptr` avoids **dangling pointer** problems.
