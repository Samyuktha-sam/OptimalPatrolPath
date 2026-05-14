# Optimal Patrol Path

A C++ computational geometry project that finds the shortest patrol boundary around multiple axis-aligned rectangles using convex hull algorithms.

Implemented algorithms:
- Andrew’s Monotone Chain
- Graham Scan

---

# Project Preview

<img width="1364" height="718" alt="Screenshot 2026-05-14 120901" src="https://github.com/user-attachments/assets/4c12ddd6-a0c2-4597-9cfa-7b08138f8ef2" />
<img width="472" height="484" alt="output" src="https://github.com/user-attachments/assets/798006a2-43c2-4f7e-ac93-9a7c50b1e8c2" />


---

##  Complexity & Conclusion
- **Monotone Chain**: `O(n log n)`  
- **Graham Scan**: `O(n log n)`  
- Both scale similarly, but Monotone Chain shows slightly better performance on large inputs.  
-  **Conclusion**: Monotone Chain is the preferred choice for efficiency.
---


## Running Instructions

### Prerequisites
- **C++ compiler** (GCC 7+, Clang 5+, or MSVC 2017+)
- **Standard library** with C++17 support
- On Windows: Use WSL (Windows Subsystem for Linux) or MinGW

### Compilation

#### CLI Solution (Judge-Ready)
```bash
g++ -std=c++17 -O2 -Iinclude src/main.cpp -o patrol
```

#### Interactive TUI
```bash
g++ -std=c++17 -O2 -Iinclude src/tui_main.cpp -o tui_patrol
```

#### Run Tests
```bash
# Monotone Chain tests
g++ -std=c++17 -O2 -Iinclude tests/test_monotone.cpp -o test_monotone
./test_monotone

# Graham Scan tests
g++ -std=c++17 -O2 -Iinclude tests/test_graham.cpp -o test_graham
./test_graham
```

### Usage

#### CLI Mode (for Automated Judges)
```bash
./patrol < input.txt > output.txt
```

**Input Format:**
```
N
x1 y1 x2 y2
x1 y1 x2 y2
...
```

**Example:**
```
2
0 0 3 4
5 5 8 8
```

**Output:**
```
26.474192
```

