# User Guide
## Issue Triage and Developer Assignment Tool

### 1. Introduction

This application helps manage software development issues and assign them to developers according to their skills and available working hours.

### 2. Starting the Application

1. Open the project folder in Visual Studio Code.
2. Open the terminal.
3. Compile the project using:

```bash
make
```

4. Run the program:

```bash
./issue_triage
```

### 3. Main Menu Options

| Option | Function |
|---|---|
| 1 | Add a new issue |
| 2 | View all issues |
| 3 | Add a developer |
| 4 | View all developers |
| 5 | Assign issues using 0/1 Knapsack |
| 6 | Update issue status |
| 7 | View project reports |
| 8 | Sort issues using Merge Sort |
| 9 | Search an issue using Binary Search |
| 10 | Save all data |
| 0 | Save and exit |

### 4. Adding an Issue

Enter the issue ID, title, description, label, module, required skill, priority, estimated hours, and dependency ID.

Priority values:
- 1 – High
- 2 – Medium
- 3 – Low

Enter dependency ID as 0 if the issue has no dependency.

### 5. Adding a Developer

Enter the developer ID, name, skill, and available working capacity in hours.

### 6. Assigning Issues

Choose option 5 to assign issues.

The application checks:
- Whether the developer has the required skill.
- Whether the issue fits within the remaining working hours.
- Whether the issue's dependency has been completed.
- Whether the issue is already assigned or completed.

The 0/1 Knapsack algorithm selects a suitable combination of issues within the developer's available capacity.

### 7. Updating Issue Status

Choose option 6 and enter the issue ID.

Select one of the following statuses:
- 0 – Open
- 1 – In Progress
- 2 – Completed

### 8. Sorting Issues

Choose option 8 to sort issues by priority using Merge Sort.

### 9. Searching Issues

Choose option 9 and enter the issue ID to search for a particular issue using Binary Search.

### 10. Viewing Reports

Choose option 7 to view:
- Total number of issues.
- Open issues.
- In-progress issues.
- Completed issues.
- Developer workload.
- Remaining developer capacity.

### 11. Saving Data

Choose option 10 to save all data.

Choose option 0 to save the data and exit the application.

The application uses two CSV files:
- `issues.csv`
- `developers.csv`

Keep both files in the project folder.

### 12. Important Notes

- Issue IDs and developer IDs should be unique.
- Priority must be between 1 and 3.
- Estimated hours must be greater than zero.
- Dependencies must refer to existing issues.
- Skill names must match exactly for assignment.
- Avoid commas inside text fields because the CSV reader uses commas as separators.