# Optimal Patrol Path

A C++ computational geometry project that finds the shortest patrol boundary around multiple axis-aligned rectangles using convex hull algorithms.

Implemented algorithms:
- Andrew’s Monotone Chain
- Graham Scan

---

# Project Preview

<img width="1364" height="718" alt="Screenshot 2026-05-14 120901" src="https://github.com/user-attachments/assets/4c12ddd6-a0c2-4597-9cfa-7b08138f8ef2" />


---

# Key Idea

Each rectangle is converted into its 4 corner points.

The shortest valid patrol boundary is the convex hull of all rectangle corners.

The final perimeter of the convex hull gives the minimum patrol path length.

---
