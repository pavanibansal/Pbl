#include "algorithms.h"

int knapsack(int weight[], int profit[], int n, int capacity)
{
    int dp[MAX_ISSUES + 1][MAX_KNAPSACK_CAPACITY + 1];

    if (n < 0 || n > MAX_ISSUES ||
        capacity < 0 || capacity > MAX_KNAPSACK_CAPACITY)
        return -1;

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

    return dp[n][capacity];
}