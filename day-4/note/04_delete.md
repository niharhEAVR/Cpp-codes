## 🔥 One Minor Issue

### ❗ Use `delete[]`, not `delete`

* `new[]` allocates an array
* `delete` is for **single object**
* `delete[]` is for **arrays**
* Using `delete` on array → **undefined behavior** (may not crash, but still incorrect)
