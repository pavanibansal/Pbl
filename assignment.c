#include <stdio.h>
#include <string.h>
#include "algorithms.h"

void assignIssues(Issue issues[], int issueCount,
                  Developer developers[], int developerCount)
{
    int weight[MAX_ISSUES], profit[MAX_ISSUES];
    int eligible[MAX_ISSUES], selected[MAX_ISSUES];
    int dp[MAX_ISSUES + 1][MAX_KNAPSACK_CAPACITY + 1];
    int assigned = 0;

    if (issueCount == 0 || developerCount == 0)
    {
        printf("\nNo issues or developers available.\n");
        return;
    }

    for (int d = 0; d < developerCount; d++)
    {
        int capacity = developers[d].capacity -
                       developers[d].assignedHours;

        if (capacity <= 0)
            continue;

        if (capacity > MAX_KNAPSACK_CAPACITY)
        {
            printf("\nCapacity of %s exceeds the supported limit of %d hours.\n",
                   developers[d].name, MAX_KNAPSACK_CAPACITY);
            continue;
        }

        int n = 0;

        for (int i = 0; i < issueCount; i++)
        {
            if (issues[i].status == 2 ||
                issues[i].assignedDeveloperId != 0 ||
                strcmp(issues[i].requiredSkill,
                       developers[d].skill) != 0 ||
                issues[i].estimatedHours > capacity)
                continue;

            int ready = 1;

            if (issues[i].dependencyId != 0)
            {
                ready = 0;

                for (int j = 0; j < issueCount; j++)
                {
                    if (issues[j].id == issues[i].dependencyId &&
                        issues[j].status == 2)
                    {
                        ready = 1;
                        break;
                    }
                }
            }

            if (ready)
            {
                weight[n] = issues[i].estimatedHours;
                profit[n] = 4 - issues[i].priority;
                eligible[n] = i;
                n++;
            }
        }

        if (n == 0)
            continue;

        for (int i = 0; i <= n; i++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                if (i == 0 || w == 0)
                    dp[i][w] = 0;
                else if (weight[i - 1] <= w)
                {
                    int include = profit[i - 1] +
                                  dp[i - 1][w - weight[i - 1]];

                    int exclude = dp[i - 1][w];

                    dp[i][w] = include > exclude ? include : exclude;
                }
                else
                    dp[i][w] = dp[i - 1][w];
            }
        }

        for (int i = 0; i < n; i++)
            selected[i] = 0;

        int w = capacity;

        for (int i = n; i > 0; i--)
        {
            if (dp[i][w] != dp[i - 1][w])
            {
                selected[i - 1] = 1;
                w -= weight[i - 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                int index = eligible[i];

                issues[index].assignedDeveloperId = developers[d].id;
                issues[index].status = 1;
                developers[d].assignedHours += weight[i];

                printf("\nIssue %d assigned to %s.\n",
                       issues[index].id, developers[d].name);

                assigned++;
            }
        }
    }

    if (assigned == 0)
        printf("\nNo suitable issues could be assigned.\n");
    else
        printf("\n%d issue(s) assigned successfully.\n", assigned);
}