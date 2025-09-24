How to **use the debugger in VS Code for C++** and actually *see all the things* (variables, call stack, breakpoints, etc.). Let’s go step by step.

---

## 🔹 Prerequisites

Before debugging works, you need:

1. **VS Code extensions**:

   * Install **C/C++** (by Microsoft).
   * (Optional) Install **CodeLLDB** or **C/C++ Extension Pack**.

2. **A compiler + debugger**:

   * On **Windows**:

     * If you use **MinGW-w64** → you get `g++` and `gdb`.
     * If you use **MSVC** (Visual Studio Build Tools) → use `cl.exe` and the MSVC debugger.
   * On **Linux/Mac**: You likely already have `g++` and `gdb`.

---

## 🔹 Step 1: Create a sample file

Example `desktop/my_workings/day-1/main.cpp`:

```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 10;
    int result = add(x, y);
    cout << "Result: " << result << endl;
    return 0;
}
```

---

## 🔹 Step 2: Compile with debug symbols

Debugging requires **symbols** (extra info about variables).
Compile with `-g`:

```bash
g++ -g main.cpp -o main
```

If you’re using MSVC (cl.exe):

```bash
cl /Zi main.cpp
```

---

## 🔹 Step 3: Setup Debugging in VS Code

1. Open your project folder in VS Code.
2. Go to **Run and Debug** sidebar → click **create a launch.json**.
3. Choose **C++ (GDB/LLDB)** or **C++ (Windows)** depending on your system.
4. A `launch.json` will be created inside `.vscode/`.

Example for **g++ + gdb**:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug C++",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/day-1/main.exe", 
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}/day-1",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "gdb"
        }
    ]
}
```

---

## 🔹 Step 4: Start Debugging

Now you can:

1. **Set breakpoints**

   * Click in the **left margin** of your code line number → red dot appears.
   * Example: put one on `int result = add(x, y);`

2. **Run debugger**

   * Press **F5** (or green ▶ button in Debug sidebar).
   * Program will pause at breakpoints.

3. **Inspect things**

   * **Variables**: See local/global variables in the **Variables pane**.
   * **Watch**: Add custom expressions (e.g., `x+y`) in **Watch pane**.
   * **Call Stack**: Shows function call history (e.g., main → add).
   * **Breakpoints**: Manage all breakpoints in one place.

4. **Step through code**

   * ▶ Continue → resume until next breakpoint.
   * ⬇ Step Over → run line, skip inside functions.
   * ↘ Step Into → go inside function (e.g., enter `add()`).
   * ↩ Step Out → finish current function and return.

---

## 🔹 Step 5: See *all the things*

* **Hover variables** → Hover mouse over `x`, `y`, or `result` to see values live.
* **Autos/Locals window** → Shows currently visible variables.
* **Memory view** (if enabled) → Inspect raw memory.
* **Registers (advanced)** → Inspect CPU registers if you’re debugging at low level.

---

✅ After this, you’ll be able to run, pause, and actually watch how your C++ program executes line by line.
