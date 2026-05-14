# Optimal Patrol Path

A C++ computational geometry project that finds the shortest patrol boundary around multiple axis-aligned rectangles using convex hull algorithms.

Implemented algorithms:
- Andrew’s Monotone Chain
- Graham Scan

---

# Project Preview

<img width="1364" height="718" alt="Screenshot 2026-05-14 120901" src="https://github.com/user-attachments/assets/4c12ddd6-a0c2-4597-9cfa-7b08138f8ef2" />


---

##  Complexity & Conclusion
- **Monotone Chain**: `O(n log n)`  
- **Graham Scan**: `O(n log n)`  
- Both scale similarly, but Monotone Chain shows slightly better performance on large inputs.  
-  **Conclusion**: Monotone Chain is the preferred choice for efficiency.
---


### 1. Clone the repository
```bash
git clone https://github.com/Samyuktha-sam/OptimalPatrolPath.git
cd OptimalPatrolPath
