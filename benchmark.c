#include <stdio.h>
#include <time.h>
#include "algorithms.h"

void benchmarkAlgorithms(void)
{
    int sizes[] = {25, 50, 100, 200};
    int numberOfSizes = 4;

    printf("\n========== ALGORITHM BENCHMARK ==========\n");
    printf("Times are measured in seconds.\n");

    for (int s = 0; s < numberOfSizes; s++)
    {
        int n = sizes[s];
        Issue issues[MAX_ISSUES];
        Issue original[MAX_ISSUES];

        int weight[MAX_ISSUES];
        int profit[MAX_ISSUES];

        for (int i = 0; i < n; i++)
        {
            original[i].id = n - i;
            original[i].priority = (i % 3) + 1;

            weight[i] = (i % 10) + 1;
            profit[i] = (i % 3) + 1;
        }

        clock_t start, end;
        double timeTaken;

        printf("\nInput size: %d\n", n);

        start = clock();

        for (int repeat = 0; repeat < 100; repeat++)
        {
            for (int i = 0; i < n; i++)
                issues[i] = original[i];

            mergeSortIssues(issues, 0, n - 1);
        }

        end = clock();
        timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Merge Sort: %.6f seconds\n", timeTaken);

        start = clock();

        for (int repeat = 0; repeat < 100; repeat++)
            binarySearchIssueIterative(original, n, n / 2);

        end = clock();
        timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Binary Search operation: %.6f seconds\n", timeTaken);

        start = clock();

        knapsack(weight, profit, n, 100);

        end = clock();
        timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("0/1 Knapsack: %.6f seconds\n", timeTaken);

        {
            static int graph[MAX_VERTICES][MAX_VERTICES];
            int distance[MAX_VERTICES];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    graph[i][j] = 0;
            }

            for (int i = 0; i < n - 1; i++)
            {
                graph[i][i + 1] = 1;
                graph[i + 1][i] = 1;
            }

            start = clock();

            dijkstraDistances(graph, n, 0, distance);

            end = clock();
            timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

            printf("Dijkstra: %.6f seconds\n", timeTaken);
        }
    }

    printf("\nBenchmark completed.\n");
}