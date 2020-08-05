#include <stdio.h>
// kadane's algorithm
// maxDiff = max(maxDiff, arr[i] - minTillNow)
// minTillNow = min(minTillNow, arr[i]);
int maxDiff(int arr[], int n)
{
    int max_diff = arr[1] - arr[0];
    int cur_min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - cur_min > max_diff)
        {
            max_diff = arr[i] - cur_min;
        }
        if (arr[i] < cur_min)
        {
            cur_min = arr[i];
        }
    }
    return max_diff;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", maxDiff(arr, n));
    }
    return 0;
}