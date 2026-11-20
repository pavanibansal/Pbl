# Complexity Report
## Issue Triage and Developer Assignment Tool

### 1. Introduction

This report describes the time and space complexity of the algorithms used in the project.

Let:
- n = Number of issues.
- k = Number of eligible issues considered for a developer.
- W = Developer's remaining working-hour capacity.
- V = Number of graph vertices.

### 2. Merge Sort

**Purpose:** Sort issues according to priority.

| Case | Time Complexity |
|---|---|
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n log n) |

Space Complexity: O(n)

Merge Sort divides the array into smaller parts, sorts them, and merges the sorted parts.

### 3. Binary Search

**Purpose:** Find an issue using its ID.

| Case | Search Time |
|---|---|
| Best Case | O(1) |
| Average Case | O(log n) |
| Worst Case | O(log n) |

Space Complexity: O(n) for the copied issue array.

**Important:** The program first sorts a copy of the issue array by ID. Therefore, the complete search operation also includes sorting and finding the original array position.

Overall Time Complexity: O(n log n).

### 4. 0/1 Knapsack

**Purpose:** Select issues within the developer's remaining working hours.

| Case | Time Complexity |
|---|---|
| Best Case | O(kW) |
| Average Case | O(kW) |
| Worst Case | O(kW) |

Space Complexity: O(kW)

The algorithm uses dynamic programming to calculate the maximum achievable priority score without exceeding the available capacity.

### 5. Dijkstra's Algorithm

**Purpose:** Calculate shortest paths in a weighted graph.

The implementation uses an adjacency matrix.

Time Complexity: O(V²)

Space Complexity: O(V) for the distance and visited arrays, excluding the graph storage.

### 6. Other Operations

| Operation | Time Complexity |
|---|---|
| Add an issue | O(n) |
| View issues | O(n) |
| Add a developer | O(d), where d is the number of developers |
| View developers | O(d) |
| Update issue status | O(n) |
| Save issues | O(n) |
| Load issues | O(n) |

### 7. Conclusion

The project uses Merge Sort for efficient issue sorting, Binary Search for issue lookup, 0/1 Knapsack for capacity-based assignment, and Dijkstra's Algorithm for shortest-path calculations.

The actual performance depends on the number of issues, developers, and graph vertices.

These are theoretical complexity estimates. No measured benchmark results are claimed in this report.