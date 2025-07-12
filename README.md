# 🚨 Route System Crash Demo — Hidden Buffer Overflow (C++)

This project demonstrates a **classic buffer overflow bug** in a route management system written in C++. It mimics a real-world issue where a silent memory corruption occurs in one function, but the crash only shows up much later in another part of the code — making it a great example for debugging practice with tools like **GDB** and **AddressSanitizer (ASan)**.

---

## 🧩 Project Overview

A fixed-size array is used internally by a `RouteManager` class to store waypoints. Due to a **missing bounds check**, the program writes beyond the array's limit, causing undefined behavior and a crash during route calculation.

---

## 📄 Files

- `route_crash_demo.cpp` – The full source code containing the bug.
- `README.md` – This documentation.

---

## 🔍 What It Demonstrates

| Feature                        | Description                                          |
|------------------------------- |------------------------------------------------------|
| Hidden buffer overflow         | Simulates a tough-to-trace memory bug                |
| Manual memory management       | C-style fixed arrays, no STL or vectors              |
| Object-oriented design         | Multi-class architecture with clean separation       |
| Debugging tools ready          | Works great with GDB,AddressSanitizer                |
| Real-world debugging flow      | Bug triggers far from where the crash happens        |

---

## ⚙️ How to Build and Run

### 🔧 Regular debug build:
```bash
g++ -g -o route_bug route_crash_demo.cpp
./route_bug
