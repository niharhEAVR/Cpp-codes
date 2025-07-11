## ✅ 1. What is Random Number Generation?

Random numbers are used in games, simulations, security, etc.
C++ provides **two ways** to generate random numbers:

### 🔸 1. Old C-style method: `rand()`

### 🔸 2. Modern C++11+ way: `<random>` library (⚠️ better)

---

# 🔷 2. Old Way: `rand()` and `srand()`

### ✅ Basic Usage:

```cpp
#include <iostream>
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time

int main() {
    srand(time(0));  // Seed the random number generator
    int r = rand();  // Returns a random number between 0 and RAND_MAX
    std::cout << "Random number: " << r << std::endl;
}
```

### 🔸 Generate number in a range (e.g., 1 to 100):

```cpp
int r = rand() % 100 + 1;  // gives number from 1 to 100
```

### 🔸 `srand(time(0))`

* Seeds the random number generator with **current time**, so it gives different numbers each time you run.
* If you don’t use `srand()`, `rand()` gives the **same sequence** every time.

---

## ⚠️ Problems with `rand()`

* Low quality randomness (not suitable for security or simulation)
* Can repeat patterns
* Hard to control distributions

---

# ✅ 3. Modern C++ Way: `<random>` (C++11 and above)

> This is the **recommended** way to generate random numbers.

### ✅ Example: Random number between 1 and 100

```cpp
#include <iostream>
#include <random>

int main() {
    std::random_device rd;                      // non-deterministic seed
    std::mt19937 gen(rd());                     // Mersenne Twister generator
    std::uniform_int_distribution<> dist(1, 100); // range: [1, 100]

    int number = dist(gen);
    std::cout << "Random number: " << number << std::endl;
}
```

---

### 🔍 Explanation of Each Part:

| Part                                      | Meaning                                        |
| ----------------------------------------- | ---------------------------------------------- |
| `std::random_device rd`                   | Generates a good seed                          |
| `std::mt19937 gen(rd())`                  | Random engine (Mersenne Twister, high quality) |
| `std::uniform_int_distribution<>(1, 100)` | Chooses numbers between 1–100                  |

---

### 🟢 You can reuse the same generator:

```cpp
for (int i = 0; i < 5; ++i) {
    std::cout << dist(gen) << " ";
}
```

---

### 🔸 Random Float Between 0.0 and 1.0

```cpp
std::uniform_real_distribution<> dist(0.0, 1.0);
double r = dist(gen);
```

---

### 🔸 Other Distributions Available:

| Distribution                | Purpose                       |
| --------------------------- | ----------------------------- |
| `uniform_int_distribution`  | Integer range                 |
| `uniform_real_distribution` | Float/double range            |
| `normal_distribution`       | Bell curve (Gaussian)         |
| `bernoulli_distribution`    | True/false like coin flip     |
| `binomial_distribution`     | Number of successes in trials |
| `poisson_distribution`      | Count of events in interval   |

---

# ✅ 4. Full Comparison Table

| Feature        | `rand()`              | `<random>` (modern)             |
| -------------- | --------------------- | ------------------------------- |
| Range control  | Limited, needs `%`    | Full control with distributions |
| Random quality | Low                   | High (cryptographic if needed)  |
| Seeding        | Manual with `srand()` | Easy with `random_device`       |
| Distribution   | Only uniform          | Many available                  |
| C++ version    | C / C++98             | C++11 and newer                 |
| Best for       | Simple, quick tasks   | Serious apps, games, security   |

---

# ✅ 5. Summary: When to Use What

| Use Case                         | Recommended Method                 |
| -------------------------------- | ---------------------------------- |
| Simple school projects           | `rand()` (but with `srand`)        |
| Games or anything range-based    | `<random>` with `uniform`          |
| Realistic simulations/statistics | `<random>` with `normal`, etc.     |
| Cryptography/security            | `std::random_device` + crypto libs |