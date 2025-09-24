## 🔹 First, the problem with private inheritance

When you inherit a class **privately**:

* `public` and `protected` members of the base class become **private** in the derived class.
* This means outside code **cannot access** them anymore through the derived object.

Example:

```cpp
class Person {
public:
    void add(int a, int b) { /* ... */ }
protected:
    std::string get_name() { return "Person"; }
};

class Engineer : private Person {
public:
    void test() {
        add(2, 3);        // ✅ allowed inside (but private to others)
        get_name();       // ✅ allowed inside
    }
};

int main() {
    Engineer e;
    e.add(2, 3);   // ❌ error: add is private in Engineer
}
```

So, **private inheritance “closes in”** the base class (like we discussed before).

---

## 🔹 Enter the `using` declaration

The `using` keyword lets you **re-expose (resurrect)** specific members from the base class into the derived class’s scope with a different access level.

Think of it like saying:

> *"Even though I inherited privately, I still want this function to be visible in my derived class as if it were public/protected again."*

---

### ✅ Example in your code

```cpp
public:
    using Person::add;
```

* Normally, `Person::add` would become **private** inside `Engineer` because of private inheritance.
* By writing `using Person::add;` inside the **public** section, you’re saying:
  👉 *“Make `add` publicly available in `Engineer` again.”*

So now:

```cpp
Engineer e;
e.add(10, 20); // ✅ Works, because of 'using Person::add;'
```

---

### ✅ Another example with protected

```cpp
protected:
    using Person::get_address;
    using Person::get_age;
```

* Normally, `get_address` and `get_age` would also become private in `Engineer`.
* But here, you’ve re-exposed them as **protected**.
* That means:

  * `Engineer` and classes derived from `Engineer` can use them.
  * But outside world (`main()`) still cannot.

---

### ❌ Why this fails

```cpp
// using Person::m_address; // Compiler error
```

* Data members (`m_address`) cannot be re-exposed with `using`.
* Only functions (methods, typedefs, enums, nested classes, etc.) can be resurrected.

That’s why the compiler complains.

---

## 🔹 General Syntax

Inside a derived class:

```cpp
using BaseClass::memberName;
```

* If placed under `public:`, the member becomes public in the derived class.
* If under `protected:`, it becomes protected.
* If under `private:`, it stays private (not very useful).

---

## 🔹 Why is this useful?

1. **Selective re-exposure**

   * You can inherit privately (hide almost everything) but selectively expose only what makes sense for your derived class.

2. **Avoids rewriting code**

   * Instead of writing wrapper functions, you just bring base functions into scope.

3. **Control over interface**

   * Helps when you want to use base functionality as implementation details, but only show *some* of them to outside users.

---

✅ **In short:**
`using` in inheritance **brings base class members into the derived class scope with the access level of the section (`public`, `protected`, `private`) where you put it.**
It’s like saying: *“I’m resurrecting this base function and giving it new visibility in my class.”*

---
---
---

We’ll use a **BankAccount** class as the base, and then derive a **SavingsAccount** using **private inheritance**.

---

## 🔹 Without `using` → everything is hidden

```cpp
#include <iostream>
#include <string>

class BankAccount {
public:
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }

    double get_balance() const {
        return balance;
    }

protected:
    std::string account_number{"123-456-789"};

private:
    double balance{0.0};
};

class SavingsAccount : private BankAccount {  // private inheritance
public:
    void apply_interest() {
        double interest = get_balance() * 0.05; // ok inside
        deposit(interest);                      // ok inside
    }
};

int main() {
    SavingsAccount sa;
    sa.deposit(1000); // ❌ ERROR: deposit is private in SavingsAccount
}
```

Here:

* `SavingsAccount` **can use** deposit/withdraw internally.
* But for the outside world (`main`), all BankAccount’s public stuff became private → unusable.

---

## 🔹 With `using` → selectively re-expose

```cpp
#include <iostream>
#include <string>

class BankAccount {
public:
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }

    double get_balance() const {
        return balance;
    }

protected:
    std::string account_number{"123-456-789"};

private:
    double balance{0.0};
};

class SavingsAccount : private BankAccount {
public:
    using BankAccount::deposit;       // expose as public
    using BankAccount::get_balance;   // expose as public

    void apply_interest() {
        double interest = get_balance() * 0.05;
        deposit(interest);
    }

protected:
    using BankAccount::withdraw;      // expose as protected
};

int main() {
    SavingsAccount sa;
    sa.deposit(1000);          // ✅ Works (thanks to using)
    sa.apply_interest();       // ✅ Adds 5% interest
    std::cout << sa.get_balance() << std::endl; // ✅ Works

    // sa.withdraw(200);       // ❌ Not allowed (protected)
}
```

---

## 🔹 Why this is good design

* **Private inheritance** hides everything by default → `SavingsAccount` is not a “BankAccount” in the outside world.
* But with `using`, we **pick only what’s relevant** (`deposit`, `get_balance`) to be part of the public API.
* Things like `withdraw` stay hidden (or protected), so the outside cannot misuse them.

---

✅ **Takeaway:**
`using` lets you **control the interface** of your derived class when you inherit privately (or protectedly). It’s like having a **filter**:

* Keep some base functions visible (`public`/`protected`)
* Keep others hidden (`private`)
