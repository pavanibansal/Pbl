
#include "algorithms.h"

void merge(Issue a[], int left, int mid, int right, int byId)
{
    Issue temp[MAX_ISSUES];
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        int x = byId ? a[i].id : a[i].priority;
        int y = byId ? a[j].id : a[j].priority;

        if (x < y || (x == y && a[i].id <= a[j].id))
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (i = left; i <= right; i++)
        a[i] = temp[i];
}

void sortIssues(Issue a[], int left, int right, int byId)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        sortIssues(a, left, mid, byId);
        sortIssues(a, mid + 1, right, byId);
        merge(a, left, mid, right, byId);
    }
}

void mergeSortIssues(Issue issues[], int left, int right)
{
    sortIssues(issues, left, right, 0);
}

int binarySearchIssueIterative(const Issue issues[], int count, int targetId)
{
    Issue temp[MAX_ISSUES];

    if (count <= 0 || count > MAX_ISSUES)
        return -1;

    for (int i = 0; i < count; i++)
        temp[i] = issues[i];

    sortIssues(temp, 0, count - 1, 1);

    int low = 0, high = count - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (temp[mid].id == targetId)
        {
            for (int i = 0; i < count; i++)
            {
                if (issues[i].id == targetId)
                    return i;
            }
        }
        else if (temp[mid].id < targetId)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
