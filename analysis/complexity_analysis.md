# Complexity Analysis - Optimal Patrol Path

## Monotone Chain

| Step          | Time           | Space    |
|---------------|---------------|----------|
| Sort 4N points| O(N log N)    | O(N)     |
| Build hull    | O(N)          | O(N)     |
| **Total**     | **O(N log N)**| **O(N)** |

## Graham Scan

| Step            | Time           | Space    |
|-----------------|---------------|----------|
| Sort by angle   | O(N log N)    | O(N)     |
| Build hull      | O(N)          | O(N)     |
| **Total**       | **O(N log N)**| **O(N)** |

## Benchmark

| N       | Monotone (ms) | Graham (ms) |
|---------|--------------|-------------|
| 1,000   | 0            | 0           |
| 10,000  | 1            | 1           |
| 50,000  | 5            | 5           |
| 100,000 | 9            | 10          |
| 200,000 | 18           | 23          |

Both are O(N log N). 
Monotone Chain is faster in practice — no angle arithmetic.