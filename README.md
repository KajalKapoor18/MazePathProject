# 🧩 MazePathProject

This C++ project explores **Backtracking Algorithms** through two classic problems:

- 🐭 **Rat in a Maze** – finding a path through a maze from a starting to an endpoint.
- 💰 **Path Counting with Exact Sum** – counting the number of ways to reach the bottom-right of a grid using only right and down moves, such that the path collects a specified coin total.


---

## 🔍 Problem Descriptions

### 1. 🐀 Rat in a Maze

- **Objective**: Find a valid path from a given start to a destination in a 5x5 maze grid.
- **Constraints**:
  - The rat can move **right** or **down**.
  - It can only move to cells with value `1`.
- **Technique**: Recursive **backtracking** – marking visited paths and backtracking when blocked.

### 2. 🧮 Path Counting with Exact Sum

- **Objective**: Count how many paths from `(0,0)` to `(R-1,C-1)` sum to a user-given value.
- **Constraints**:
  - Allowed moves: **Right** or **Down**.
  - Each cell contains a coin value.
- **Technique**: Recursively calculate the number of ways subtracting the current cell value from the target.

---


