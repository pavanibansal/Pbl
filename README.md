# Issue Triage and Developer Assignment Tool

## Project Overview

The Issue Triage and Developer Assignment Tool is a C-based application designed to manage software development issues and assign tasks to developers based on priority, skills, dependencies, and available working hours.

The project demonstrates the practical use of Design and Analysis of Algorithms concepts.

## Technologies Used
- C17
- Visual Studio Code
- CSV files for data storage
- Makefile for compilation

## Algorithms Implemented

1. **Merge Sort:** Sorts issues according to priority. Issue ID is used to break ties.
2. **Binary Search:** Searches for an issue using its ID.
3. **0/1 Knapsack:** Selects suitable issues within a developer's available working hours.
4. **Dijkstra's Algorithm:** Implements shortest-path calculation on a weighted graph.

## Main Features

- Add and view software issues.
- Add and view developers.
- Assign issues based on skills and available capacity.
- Update issue status.
- Generate project and developer reports.
- Sort issues by priority.
- Search issues by ID.
- Save and load data using CSV files.

## Project Files

- `main.c` – Main menu and program execution.
- `models.h` – Issue and developer structures.
- `algorithms.h` – Function declarations.
- `issues.c` – Issue management.
- `developers.c` – Developer management.
- `assignment.c` – Issue assignment using 0/1 Knapsack.
- `sorting_searching.c` – Merge Sort and Binary Search.
- `graph.c` – Dijkstra's Algorithm.
- `dynamic_programming.c` – Knapsack implementation.
- `persistence.c` – CSV file handling.
- `reports.c` – Project reports.
- `Makefile` – Compilation instructions.
- `issues.csv` – Issue dataset.
- `developers.csv` – Developer dataset.

## How to Run

Open the project folder in VS Code and open its terminal.

Compile the project:

```bash
make
```

Run the application:

```bash
./issue_triage
```

## Data Storage

The application stores issue information in `issues.csv` and developer information in `developers.csv`. Both files should remain in the same folder as the executable.

Use the Save All Data option or Save and Exit to save changes.

## Conclusion

This project demonstrates how algorithmic techniques can be applied to software issue management, prioritization, searching, dependency analysis, and developer workload allocation.