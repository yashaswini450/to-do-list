# 📝 Simple C++ To-Do List

A lightweight, blazing-fast CLI To-Do List application. This document outlines the core architectural decisions, code characteristics, and data structures for building the app entirely in standard C++ with zero external dependencies.

## 🏗️ Core Architectural Decisions

To keep things as simple and robust as possible, we are relying purely on standard C++ capabilities—no build systems, no third-party frameworks.

| Decision Area | Selected Technology | Rationale |
| :--- | :--- | :--- |
| **Programming Language** | **C++ (C++17 or later)** | Maximum performance, zero runtime overhead, and strict type safety. |
| **Tech Stack** | **C++ Standard Library** | The standard library (`<fstream>`, `<iostream>`, `<vector>`) provides everything needed. No build systems required—just compile directly from the terminal. |
| **User Interface (UI)** | **Command Line Interface (CLI)** | The absolute simplest approach. Users interact via the terminal, completely eliminating the need for complex GUI state management. *(Fallback: If a GUI is ever needed, we can wrap this C++ core with Python/Tkinter later).* |
| **Portability** | **Cross-Platform Source Code** | Standard C++ code runs anywhere. You can compile it natively on Windows (MSVC), macOS (Clang), or Linux (GCC) with a single command (e.g., `g++ main.cpp -o todo`). |

---

## ✨ Code Aspects & Desirable Characteristics

The codebase focuses on the KISS (Keep It Simple, Stupid) principle while remaining robust:

*   **Resilience via Text Persistence:** 
    Tasks are saved to and loaded from a simple flat file (e.g., `tasks.txt`) using `std::fstream`. If the app crashes or is closed, the data is already safe on the disk.
*   **Performance via Value Semantics:** 
    C++ allows us to pass data by `const` reference, avoiding unnecessary memory allocations and copies when iterating through the task list.
*   **Memory Safety:** 
    By strictly using standard library containers (like `std::vector` and `std::string`), we avoid raw pointers and manual memory management (`new`/`delete`), eliminating memory leaks.
*   **Separation of Concerns:** 
    The file parsing/saving logic, the list management, and the terminal drawing are separated into distinct classes or namespaces. This makes it incredibly easy to swap out the terminal UI for a Python GUI later if desired.

---

## 🗄️ Data Structures

We keep the memory footprint tiny by using standard, cache-friendly C++ data structures.

### The Task Object
A simple C++ `struct` groups the two required properties.

```cpp
struct Task {
    std::string description;
    bool isCompleted;
};
