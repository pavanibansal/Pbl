# Design Document
## Issue Triage and Developer Assignment Tool

### 1. Project Description

The Issue Triage and Developer Assignment Tool is developed using C. It helps manage software issues and assign them to developers according to priority, skill requirements, dependencies, and available working hours.

The project applies important Design and Analysis of Algorithms concepts to a practical software development problem.

### 2. Objectives

- Maintain a collection of software issues.
- Store developer details and working capacity.
- Sort issues according to priority.
- Search for issues using their IDs.
- Assign suitable issues to developers.
- Consider completed dependencies before assignment.
- Display project and developer reports.
- Store information permanently using CSV files.

### 3. System Design

The application is divided into separate C source and header files.

| File | Responsibility |
|---|---|
| `main.c` | Main menu and program control |
| `models.h` | Issue and Developer structures |
| `algorithms.h` | Function declarations |
| `issues.c` | Issue management |
| `developers.c` | Developer management |
| `assignment.c` | Developer assignment |
| `sorting_searching.c` | Sorting and searching |
| `dynamic_programming.c` | Knapsack implementation |
| `graph.c` | Dijkstra's Algorithm |
| `persistence.c` | File loading and saving |
| `reports.c` | Report generation |

### 4. Data Structures

**Issue Structure**

Stores:
- Issue ID
- Title and description
- Label and module
- Required skill
- Priority
- Estimated hours
- Dependency ID
- Assigned developer ID
- Status

**Developer Structure**

Stores:
- Developer ID
- Name
- Skill
- Total capacity
- Assigned working hours

### 5. Algorithms Used

#### A. Merge Sort

Used to arrange issues according to priority.

Issues with the same priority are arranged according to their IDs.

#### B. Binary Search

Used to search for an issue using its ID.

The program creates a sorted copy of the issue list before performing Binary Search, so the original issue order is preserved.

#### C. 0/1 Knapsack

Used to select a suitable combination of issues for each developer.

Each issue is treated as an item:
- Weight = Estimated working hours.
- Profit = Priority score.
- Capacity = Developer's remaining working hours.

The algorithm selects issues without exceeding the developer's available capacity.

Only issues with matching skills and completed dependencies are considered.

#### D. Dijkstra's Algorithm

Implemented in `graph.c` to calculate shortest paths in a weighted graph using an adjacency matrix.

The current main menu does not directly invoke this function.

### 6. Working Process

1. Load existing issues and developers from CSV files.
2. Display the main menu.
3. Accept user operations.
4. Add, view, sort, search, or update issue information.
5. Assign suitable issues to developers.
6. Generate reports.
7. Save updated information to CSV files.
8. Exit the application.

### 7. File Storage

The application uses CSV files to store issue and developer records.

This allows information to remain available after the program is closed.

### 8. Expected Output

The application displays:
- Issue information.
- Developer information.
- Sorted issue lists.
- Search results.
- Assignment results.
- Project statistics.
- Developer workload reports.

### 9. Conclusion

The project demonstrates the application of sorting, searching, dynamic programming, and graph algorithms in a software issue management system.