#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        int n;
        scanf("%d", &n);
        long long int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        sort(arr, arr + n);
        printf("%lld\n", max(arr[0] * arr[1] * arr[n - 1], arr[n - 1] * arr[n - 2] * arr[n - 3]));
    }
    return 0;
}