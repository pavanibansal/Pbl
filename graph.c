#include <stdio.h>
#include "algorithms.h"

#define INF 999999

void dijkstraDistances(int graph[MAX_VERTICES][MAX_VERTICES],
                       int n, int source, int distance[])
{
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < n; i++)
        distance[i] = INF;

    distance[source] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int min = INF;
        int u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] < min)
            {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] > 0 &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES],
              int n, int source)
{
    int distance[MAX_VERTICES];

    if (n <= 0 || n > MAX_VERTICES ||
        source < 0 || source >= n)
    {
        printf("Invalid graph or source.\n");
        return;
    }

    dijkstraDistances(graph, n, source, distance);

    for (int i = 0; i < n; i++)
    {
        if (i == source)
            printf("Vertex %d (source): 0\n", i);
        else if (distance[i] == INF)
            printf("Vertex %d: No path\n", i);
        else
            printf("Vertex %d: %d\n", i, distance[i]);
    }
}

void showDependencyPaths(const Issue issues[], int issueCount)
{
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int distance[MAX_VERTICES];

    if (issueCount <= 0 || issueCount > MAX_VERTICES)
        return;

    for (int i = 0; i < issueCount; i++)
    {
        if (issues[i].dependencyId == 0)
            continue;

        for (int j = 0; j < issueCount; j++)
        {
            if (issues[j].id == issues[i].dependencyId)
            {
                int weight = issues[i].estimatedHours;

                if (weight <= 0)
                    weight = 1;

                graph[i][j] = weight;
                graph[j][i] = weight;
                break;
            }
        }
    }

    dijkstraDistances(graph, issueCount, 0, distance);

    printf("\n===== DEPENDENCY PATH REPORT =====\n");
    printf("Starting issue: %d\n", issues[0].id);

    for (int i = 0; i < issueCount; i++)
    {
        if (i == 0)
            continue;

        if (distance[i] == INF)
            printf("Issue %d: No dependency path\n", issues[i].id);
        else
            printf("Issue %d: %d hours\n",
                   issues[i].id, distance[i]);
    }
}