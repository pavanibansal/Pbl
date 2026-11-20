
#ifndef MODELS_H
#define MODELS_H

#define MAX_ISSUES 200
#define MAX_DEVELOPERS 100
#define MAX_TEXT 100
#define MAX_SKILL 50

typedef struct
{
    int id;
    char title[MAX_TEXT];
    char description[300];
    char label[MAX_SKILL];
    char module[MAX_SKILL];
    char requiredSkill[MAX_SKILL];
    int priority;
    int estimatedHours;
    int dependencyId;
    int assignedDeveloperId;
    int status;
} Issue;

typedef struct
{
    int id;
    char name[MAX_TEXT];
    char skill[MAX_SKILL];
    int capacity;
    int assignedHours;
} Developer;

#endif
