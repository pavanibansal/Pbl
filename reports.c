#include <stdio.h>
#include "algorithms.h"

void showReports(const Issue issues[], int issueCount,
                 const Developer developers[], int developerCount)
{
    int open = 0;
    int progress = 0;
    int completed = 0;

    for (int i = 0; i < issueCount; i++)
    {
        if (issues[i].status == 0)
            open++;
        else if (issues[i].status == 1)
            progress++;
        else if (issues[i].status == 2)
            completed++;
    }

    printf("\n========== PROJECT REPORT ==========\n");
    printf("Total Issues: %d\n", issueCount);
    printf("Open Issues: %d\n", open);
    printf("In Progress Issues: %d\n", progress);
    printf("Completed Issues: %d\n", completed);

    printf("\n========== DEVELOPER REPORT ==========\n");

    for (int i = 0; i < developerCount; i++)
    {
        printf("\nDeveloper: %s\n", developers[i].name);
        printf("Skill: %s\n", developers[i].skill);
        printf("Assigned Hours: %d\n", developers[i].assignedHours);
        printf("Remaining Hours: %d\n",
               developers[i].capacity - developers[i].assignedHours);
    }

    showDependencyPaths(issues, issueCount);

    printf("\n=====================================\n");
}