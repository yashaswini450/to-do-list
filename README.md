# 📝 To-Do App: C++ Architecture & Implementation Guide

A dead-simple, highly portable Command Line Interface (CLI) To-Do List application. This document outlines the core architectural decisions, coding standards, and data structures for building this app entirely in C++.

## 🏗️ Core Architectural Decisions

Keeping things simple and efficient by relying on standard tools and avoiding unnecessary framework bloat.

| Decision Area | Selected Technology | Rationale |
| :--- | :--- | :--- |
| **Programming Language** | **C++** (Core) / **Python** (Fallback) | C++ handles the core logic and memory efficiently. Python is kept in reserve for rapid prototyping or simple build/test scripts if needed. |
| **Tech Stack** | **Standard C++ Library (STL) + CMake** | No heavy dependencies. The STL provides everything needed for data structures and file I/O. CMake ensures the project can be built easily on any OS. |
| **User Interface (UI)** | **Command Line Interface (CLI)** | Maximum simplicity. A text-based menu system (`std::cin` / `std::cout`) avoids the complexity of GUI frameworks like Qt or ImGui, keeping the codebase small and focused. |
| **Portability** | **Cross-Platform Compilation** | By sticking strictly to the C++ Standard Library and CMake, the application compiles and runs natively on Windows, macOS, and Linux without modification. |

---

## ✨ Code Aspects & Desirable Characteristics

The codebase is structured to be robust, readable, and easy to maintain without over-engineering.

*   **Resilience via Persistent Storage:** 
    Tasks are saved to a simple text or CSV file using `std::ofstream`. On startup, `std::ifstream` loads the tasks into memory. This guarantees your to-do list survives application restarts.
*   **Maintainability via Decoupled Logic:** 
    The core `TaskManager` class (handling add/toggle/delete operations) is kept entirely separate from the CLI input/output loop. If you ever decide to add a Python GUI (like Tkinter) later, the core C++ logic remains untouched.
*   **Memory Safety via RAII:** 
    Modern C++ practices are strictly enforced. We use standard containers and stack allocation to automatically manage memory, completely avoiding raw pointers and manual `new`/`delete` calls to prevent memory leaks.
*   **Simplicity over Premature Optimization (KISS):** 
    Code prioritizes readability over micro-optimizations. Algorithms are kept straightforward because a personal to-do list does not require complex data handling.

---

## 🗄️ Data Structures

We use standard, lightweight C++ structures to manage task data efficiently.

### The Task Object
Each task is represented as a basic `struct` holding the two required properties and an ID.

```cpp
#include <string>

struct Task {
    int id;                 // Sequential ID for easy CLI selection
    std::string description;// The text content of the task
    bool isCompleted;       // Completion status (true = done, false = pending)
};
