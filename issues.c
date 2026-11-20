
#include <stdio.h>
#include <string.h>
#include "algorithms.h"

void clearInput(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

void readText(char text[], int size)
{
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

void addIssue(Issue issues[], int *issueCount)
{
    Issue newIssue;
    int exists = 0;

    if (*issueCount >= MAX_ISSUES)
    {
        printf("\nIssue limit reached.\n");
        return;
    }

    printf("\nEnter Issue ID: ");
    scanf("%d", &newIssue.id);
    clearInput();

    for (int i = 0; i < *issueCount; i++)
    {
        if (issues[i].id == newIssue.id)
        {
            exists = 1;
            break;
        }
    }

    if (exists || newIssue.id <= 0)
    {
        printf("Invalid or duplicate Issue ID.\n");
        return;
    }

    printf("Enter Issue Title: ");
    readText(newIssue.title, MAX_TEXT);

    printf("Enter Description: ");
    readText(newIssue.description, 300);

    printf("Enter Label: ");
    readText(newIssue.label, MAX_SKILL);

    printf("Enter Module: ");
    readText(newIssue.module, MAX_SKILL);

    printf("Enter Required Skill: ");
    readText(newIssue.requiredSkill, MAX_SKILL);

    printf("Enter Priority (1=High, 2=Medium, 3=Low): ");
    scanf("%d", &newIssue.priority);

    if (newIssue.priority < 1 || newIssue.priority > 3)
    {
        printf("Invalid priority.\n");
        clearInput();
        return;
    }

    printf("Enter Estimated Hours: ");
    scanf("%d", &newIssue.estimatedHours);

    if (newIssue.estimatedHours <= 0)
    {
        printf("Hours must be greater than zero.\n");
        clearInput();
        return;
    }

    printf("Enter Dependency Issue ID (0 if none): ");
    scanf("%d", &newIssue.dependencyId);
    clearInput();

    if (newIssue.dependencyId == newIssue.id ||
        newIssue.dependencyId < 0)
    {
        printf("Invalid dependency.\n");
        return;
    }

    if (newIssue.dependencyId != 0)
    {
        exists = 0;

        for (int i = 0; i < *issueCount; i++)
        {
            if (issues[i].id == newIssue.dependencyId)
            {
                exists = 1;
                break;
            }
        }

        if (!exists)
        {
            printf("Dependency Issue ID does not exist.\n");
            return;
        }
    }

    newIssue.assignedDeveloperId = 0;
    newIssue.status = 0;

    issues[*issueCount] = newIssue;
    (*issueCount)++;

    printf("\nIssue added successfully.\n");
}

void viewIssues(const Issue issues[], int issueCount)
{
    if (issueCount == 0)
    {
        printf("\nNo issues available.\n");
        return;
    }

    printf("\n================ ISSUE LIST ================\n");

    for (int i = 0; i < issueCount; i++)
    {
        printf("\nIssue ID: %d\n", issues[i].id);
        printf("Title: %s\n", issues[i].title);
        printf("Description: %s\n", issues[i].description);
        printf("Label: %s\n", issues[i].label);
        printf("Module: %s\n", issues[i].module);
        printf("Required Skill: %s\n", issues[i].requiredSkill);

        printf("Priority: ");
        if (issues[i].priority == 1)
            printf("High\n");
        else if (issues[i].priority == 2)
            printf("Medium\n");
        else
            printf("Low\n");

        printf("Estimated Hours: %d\n", issues[i].estimatedHours);

        if (issues[i].dependencyId == 0)
            printf("Dependency: None\n");
        else
            printf("Dependency: Issue %d\n", issues[i].dependencyId);

        printf("Assigned Developer ID: %d\n",
               issues[i].assignedDeveloperId);

        printf("Status: ");
        if (issues[i].status == 0)
            printf("Open\n");
        else if (issues[i].status == 1)
            printf("In Progress\n");
        else
            printf("Completed\n");

        printf("--------------------------------------------\n");
    }
}

void updateIssueStatus(Issue issues[], int issueCount)
{
    int id, newStatus;
    int found = -1;

    if (issueCount == 0)
    {
        printf("\nNo issues available.\n");
        return;
    }

    printf("\nEnter Issue ID: ");
    scanf("%d", &id);

    for (int i = 0; i < issueCount; i++)
    {
        if (issues[i].id == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Issue not found.\n");
        return;
    }

    printf("\nChoose New Status:\n");
    printf("0. Open\n");
    printf("1. In Progress\n");
    printf("2. Completed\n");
    printf("Enter status: ");
    scanf("%d", &newStatus);

    if (newStatus < 0 || newStatus > 2)
    {
        printf("Invalid status.\n");
        return;
    }

    issues[found].status = newStatus;

    if (newStatus == 0)
        issues[found].assignedDeveloperId = 0;

    printf("\nIssue status updated successfully.\n");
}
