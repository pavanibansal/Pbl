#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "models.h"

#define MAX_VERTICES 200
#define MAX_KNAPSACK_CAPACITY 1000

void addIssue(Issue issues[], int *issueCount);
void viewIssues(const Issue issues[], int issueCount);
void updateIssueStatus(Issue issues[], int issueCount);

void addDeveloper(Developer developers[], int *developerCount);
void viewDevelopers(const Developer developers[], int developerCount);

void assignIssues(Issue issues[], int issueCount,
                  Developer developers[], int developerCount);

void showReports(const Issue issues[], int issueCount,
                 const Developer developers[], int developerCount);

void showDependencyPaths(const Issue issues[], int issueCount);

int loadIssues(Issue issues[], int *issueCount, const char *filename);
int saveIssues(const Issue issues[], int issueCount, const char *filename);

int loadDevelopers(Developer developers[], int *developerCount,
                   const char *filename);
int saveDevelopers(const Developer developers[], int developerCount,
                   const char *filename);

void mergeSortIssues(Issue issues[], int left, int right);
int binarySearchIssueIterative(const Issue issues[], int count, int targetId);

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES],
              int n, int source);
void dijkstraDistances(int graph[MAX_VERTICES][MAX_VERTICES],
                       int n, int source, int distance[]);

int knapsack(int weight[], int profit[], int n, int capacity);

void benchmarkAlgorithms(void);

#endif