#include <stdio.h>
#include "algorithms.h"

void saveAll(Issue issues[], int issueCount,
             Developer developers[], int developerCount)
{
    if (saveIssues(issues, issueCount, "issues.csv") &&
        saveDevelopers(developers, developerCount, "developers.csv"))
        printf("\nData saved successfully.\n");
    else
        printf("\nError saving data.\n");
}

int main(void)
{
    Issue issues[MAX_ISSUES];
    Developer developers[MAX_DEVELOPERS];

    int issueCount = 0;
    int developerCount = 0;
    int choice, targetId, position;

    loadIssues(issues, &issueCount, "issues.csv");
    loadDevelopers(developers, &developerCount, "developers.csv");

    do
    {
        printf("\n===== ISSUE TRIAGE AND DEVELOPER ASSIGNMENT =====\n");
        printf("1. Add Issue\n");
        printf("2. View Issues\n");
        printf("3. Add Developer\n");
        printf("4. View Developers\n");
        printf("5. Assign Issues using 0/1 Knapsack\n");
        printf("6. Update Issue Status\n");
        printf("7. View Reports\n");
        printf("8. Sort Issues using Merge Sort\n");
        printf("9. Search Issue using Binary Search\n");
        printf("10. Save All Data\n");
        printf("11. Run Algorithm Benchmark\n");
        printf("12. Run Dijkstra Dependency Analysis\n");
        printf("0. Save and Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addIssue(issues, &issueCount);
                break;

            case 2:
                viewIssues(issues, issueCount);
                break;

            case 3:
                addDeveloper(developers, &developerCount);
                break;

            case 4:
                viewDevelopers(developers, developerCount);
                break;

            case 5:
                assignIssues(issues, issueCount,
                             developers, developerCount);
                break;

            case 6:
                updateIssueStatus(issues, issueCount);
                break;

            case 7:
                showReports(issues, issueCount,
                            developers, developerCount);
                break;

            case 8:
                if (issueCount > 0)
                {
                    mergeSortIssues(issues, 0, issueCount - 1);
                    printf("\nIssues sorted by priority.\n");
                    viewIssues(issues, issueCount);
                }
                else
                    printf("\nNo issues available.\n");
                break;

            case 9:
                printf("Enter Issue ID to search: ");
                scanf("%d", &targetId);

                position = binarySearchIssueIterative(
                    issues, issueCount, targetId);

                if (position != -1)
                {
                    printf("\nIssue found:\n");
                    printf("ID: %d\n", issues[position].id);
                    printf("Title: %s\n", issues[position].title);
                    printf("Priority: %d\n", issues[position].priority);
                }
                else
                    printf("\nIssue not found.\n");
                break;

            case 10:
                saveAll(issues, issueCount,
                        developers, developerCount);
                break;

            case 11:
                benchmarkAlgorithms();
                break;
            case 12:
                showDependencyPaths(issues, issueCount);
                break;

            case 0:
                saveAll(issues, issueCount,
                        developers, developerCount);
                printf("\nThank you for using the project.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}
