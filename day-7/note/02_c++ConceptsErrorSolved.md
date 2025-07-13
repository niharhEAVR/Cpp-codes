The error:

> **`identifier "requires" is undefined C/C++(20)`**

means your **compiler does not recognize the `requires` keyword**, which is part of **C++20 concepts**.

---

## ✅ How to Fix It

The `requires` keyword and concepts are available in **C++20** or later. So you must:

* Use a modern compiler
* Enable C++20 or higher


## ✅ Step-by-Step: Enable C++20 in VS Code

### ✅ 1. Open or Create a `tasks.json` (for building your code)

1. Press `Ctrl+Shift+P` → type `Tasks: Configure Default Build Task`
2. Choose `C/C++: g++ build active file`
3. VS Code will create or open `.vscode/tasks.json`

### ✅ 2. Modify `tasks.json` to enable C++20

Change it like this (or modify the `args` section):

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "g++ build active file",
      "command": "/usr/bin/g++", // or just "g++" if it's in PATH
      "args": [
        "-std=c++20", // ✅ this enables C++20
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"],
      "detail": "Compiler: g++"
    }
  ]
}
```

> 🟨 If you're using MinGW on Windows, your `command` might be `"g++"` or `"C:\\mingw64\\bin\\g++.exe"`

---

### ✅ 3. Also ensure IntelliSense uses C++20 (optional)

Go to `.vscode/c_cpp_properties.json`
If it doesn’t exist, run:

> `Ctrl+Shift+P` → `C/C++: Edit Configurations (UI)`

In the file:

```json
{
  "configurations": [
    {
      "name": "Win32",
      "includePath": [
        "${workspaceFolder}/**"
      ],
      "defines": [],
      "compilerPath": "C:/mingw64/bin/g++.exe", // your actual g++ path
      "cStandard": "c17",
      "cppStandard": "c++20", // ✅ Set this
      "intelliSenseMode": "windows-gcc-x64"
    }
  ],
  "version": 4
}
```

---

### ✅ 4. Now build and run

After setting this:

* `Ctrl+Shift+B` → select `g++ build active file`
* Your code using `requires` and `std::integral` will now compile correctly.


---
---
---



You're using the **Code Runner extension** in VS Code, which by default **does NOT add `-std=c++20`** or use `g++.exe` properly for C++20 features like `requires`.

---

## ✅ The Problem:

Code Runner runs a default command like:

```bash
gcc test.cpp -o test
```

This:

* Uses `gcc` (C compiler, not `g++`)
* Doesn't pass `-std=c++20`
* Causes errors like `requires does not name a type`

---
### 🛠 Configure Code Runner to Use `g++ -std=c++20`

If you still want to use Code Runner (`Run Code` button), do this:

#### ➤ Open VS Code Settings (`Ctrl + ,`)

Search for: `code-runner.executorMap`

Then click **"Edit in settings.json"** and update this:

```json
"code-runner.executorMap": {
    "cpp": "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
}
```

With this:

```json
"code-runner.executorMap": {
    "cpp": "cpp": "cd $dir && g++ -std=c++20 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
}
```

✅ This forces Code Runner to:

* Use `g++`
* Use `-std=c++20`
* Compile and run your C++20 code properly