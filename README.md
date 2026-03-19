# C + WebAssembly (WASM) Starter

Welcome to my first **C + WebAssembly** project! 
I created this to study **Computer Science fundamentals**, understand how low-level memory is managed, and figure out how to bridge the gap between application web stacks (React/JS) and system performance scripts.

This project is a simple **Goods Accounting System** that allocates structures of products in local memory, walks through addresses using pointers, and prints it right inside the browser window.

---

### Result
You can see the result without cloning this repo by this link https://filippovskii09.github.io/simple-wasm-c/

---

## 💡 Concepts & Terms

To understand how this works, here are the main building blocks:

*   **⚡️ C Language:** A fast, low-level language that treats memory directly with pointers. 
*   **🦀 WebAssembly (WASM):** A binary layout format. Think of it as safe, native-speed machine code running inside the browser side-by-side with JavaScript.
*   **🛠 Emscripten (`emcc`):** A compiler that takes C code and translates it into a `.wasm` file, and creates a `.js` **glue-code** script representing to DOM.

---

## 📂 What do these files do?

*   `main.c` 📝: The actual **C logic**. Defines structures, increments memory pointers (`ptr++`), iterates arrays using raw memory sizing.
*   `index.html` 📋: The wrapper. It intercepts standard C output (like `printf()`) and renders it directly on the screen's DOM container.
*   `a.out.wasm` 📦: The raw **binary machine code** produced by the compilation.
*   `a.out.js` 🔗: **Glue code**. JS wrapper script responsible for loading `.wasm`, setting up memory buffers, and talking to C.

---

## 🛠 Prerequisites

You'll need a few tools on your machine to test or rebuild this.

### 1. Standard C Compiler (For local C tests)
*   **macOS:** You likely have `gcc` / `clang` ready. Check with `gcc --version` in terminal. 
*   If missing, run: `xcode-select --install`.

### 2. Emscripten (For WASM pipeline)
The easiest way on Mac using **Homebrew**:
```bash
brew install emscripten
```

---

## 🚀 Getting Started

### Structures

**src**     - folder with source code
**build**   - folder with compiled code
**www**     - folder with web interface(html, js, wasm)


### 1️⃣ Clone the Repository
```bash
git clone https://github.com/your-username/simple_wasm.git
cd simple_wasm
```

### 2️⃣ Test C Code Locally (Terminal)
Before taking it to the web, let's make sure pure C handles logic:
```bash
# Compile
gcc main.c -o main

# Run
./main
```
*You will see the product warehouse inventory dumped right into your Terminal.*

---

### 3️⃣ Compile into sub-Web (WASM)
To rebuild the browser artifacts, use Emscripten:
```bash
emcc -O3 -s WASM=1 -s EXPORTED_RUNTIME_METHODS='["cwrap"]' main.c
```
*Creates `a.out.js` and `a.out.wasm`.*

---

### 4️⃣ Run in Browser
Because of CORS safety policies, compiled scripts must be run over an HTTP stream, not just by double-clicking `.html` locally.

1. Install the **Live Server** extension in VS Code.
2. Open `index.html`.
3. Right-click inside the index code $\rightarrow$ select **Open with Live Server**.
4. 🎉 **Done!** You are officially running static C inside a dynamic HTML element!

---

## 🔗 Meet the Tech
*   [WebAssembly.org](https://webassembly.org/)
*   [Emscripten Docs](https://emscripten.org/)
