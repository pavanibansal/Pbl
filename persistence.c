
#include <stdio.h>
#include "algorithms.h"

int loadIssues(Issue issues[], int *issueCount, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    char line[700];

    *issueCount = 0;

    if (fp == NULL)
        return 0;

    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL &&
           *issueCount < MAX_ISSUES)
    {
        Issue x;

        if (sscanf(line,
            "%d,%99[^,],%299[^,],%49[^,],%49[^,],%49[^,],%d,%d,%d,%d,%d",
            &x.id, x.title, x.description, x.label, x.module,
            x.requiredSkill, &x.priority, &x.estimatedHours,
            &x.dependencyId, &x.assignedDeveloperId, &x.status) == 11)
        {
            issues[*issueCount] = x;
            (*issueCount)++;
        }
    }

    fclose(fp);
    return 1;
}

int saveIssues(const Issue issues[], int issueCount, const char *filename)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
        return 0;

    fprintf(fp, "ID,Title,Description,Label,Module,RequiredSkill,Priority,Hours,Dependency,Developer,Status\n");

    for (int i = 0; i < issueCount; i++)
    {
        fprintf(fp, "%d,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d\n",
                issues[i].id, issues[i].title,
                issues[i].description, issues[i].label,
                issues[i].module, issues[i].requiredSkill,
                issues[i].priority, issues[i].estimatedHours,
                issues[i].dependencyId,
                issues[i].assignedDeveloperId, issues[i].status);
    }

    fclose(fp);
    return 1;
}

int loadDevelopers(Developer developers[], int *developerCount,
                   const char *filename)
{
    FILE *fp = fopen(filename, "r");
    char line[300];

    *developerCount = 0;

    if (fp == NULL)
        return 0;

    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL &&
           *developerCount < MAX_DEVELOPERS)
    {
        Developer d;

        if (sscanf(line, "%d,%99[^,],%49[^,],%d,%d",
                   &d.id, d.name, d.skill,
                   &d.capacity, &d.assignedHours) == 5)
        {
            developers[*developerCount] = d;
            (*developerCount)++;
        }
    }

    fclose(fp);
    return 1;
}

int saveDevelopers(const Developer developers[], int developerCount,
                   const char *filename)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
        return 0;

    fprintf(fp, "ID,Name,Skill,Capacity,AssignedHours\n");

    for (int i = 0; i < developerCount; i++)
    {
        fprintf(fp, "%d,%s,%s,%d,%d\n",
                developers[i].id, developers[i].name,
                developers[i].skill, developers[i].capacity,
                developers[i].assignedHours);
    }

    fclose(fp);
    return 1;
}
