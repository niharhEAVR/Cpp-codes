### 🔹 **Statements in C++ – Short Notes**

A **statement** in C++ is a complete instruction that tells the compiler to perform a specific action.

---

### ✅ **Types of Statements in C++:**

1. **Expression Statement:**

   * Performs a calculation or operation.
   * Ends with a semicolon `;`
   * Example:

     ```cpp
     x = a + b;
     ```

2. **Declaration Statement:**

   * Declares variables or constants.
   * Example:

     ```cpp
     int x;
     ```

3. **Compound Statement (Block):**

   * A group of statements enclosed in `{ }`
   * Example:

     ```cpp
     {
         int a = 5;
         cout << a;
     }
     ```

4. **Control Statement:**

   * Controls the flow of program execution.
   * Examples:

     * `if`, `else`
     * `for`, `while`, `do-while`
     * `switch`, `break`, `continue`, `goto`

5. **Jump Statement:**

   * Transfers control.
   * Examples:

     * `break;`, `continue;`, `return;`, `goto label;`

---

### 📝 Example:

```cpp
int a = 5;              // Declaration + Expression Statement
if (a > 0)              // Control Statement
{
    cout << "Positive"; // Expression inside Block
}
```