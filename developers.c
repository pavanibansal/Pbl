
#include <stdio.h>
#include <string.h>
#include "algorithms.h"

void addDeveloper(Developer developers[], int *developerCount)
{
    Developer newDeveloper;
    int exists = 0;

    if (*developerCount >= MAX_DEVELOPERS)
    {
        printf("\nDeveloper limit reached.\n");
        return;
    }

    printf("\nEnter Developer ID: ");
    scanf("%d", &newDeveloper.id);

    for (int i = 0; i < *developerCount; i++)
    {
        if (developers[i].id == newDeveloper.id)
        {
            exists = 1;
            break;
        }
    }

    if (exists || newDeveloper.id <= 0)
    {
        printf("Invalid or duplicate Developer ID.\n");
        return;
    }

    printf("Enter Developer Name: ");
    scanf(" %99[^\n]", newDeveloper.name);

    printf("Enter Developer Skill: ");
    scanf(" %49[^\n]", newDeveloper.skill);

    printf("Enter Available Capacity in Hours: ");
    scanf("%d", &newDeveloper.capacity);

    if (newDeveloper.capacity <= 0)
    {
        printf("Capacity must be greater than zero.\n");
        return;
    }

    newDeveloper.assignedHours = 0;

    developers[*developerCount] = newDeveloper;
    (*developerCount)++;

    printf("\nDeveloper added successfully.\n");
}

void viewDevelopers(const Developer developers[], int developerCount)
{
    if (developerCount == 0)
    {
        printf("\nNo developers available.\n");
        return;
    }

    printf("\n============= DEVELOPER LIST =============\n");

    for (int i = 0; i < developerCount; i++)
    {
        printf("\nDeveloper ID: %d\n", developers[i].id);
        printf("Name: %s\n", developers[i].name);
        printf("Skill: %s\n", developers[i].skill);
        printf("Total Capacity: %d hours\n", developers[i].capacity);
        printf("Assigned Hours: %d hours\n", developers[i].assignedHours);
        printf("Remaining Hours: %d hours\n",
               developers[i].capacity - developers[i].assignedHours);

        printf("-----------------------------------------\n");
    }
}
