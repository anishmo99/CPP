#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int sumCloseToZero(int arr[], int n)
{
    sort(arr, arr + n);
    int low = 0;
    int high = n - 1;
    int sum, ans = INT_MAX;
    while (low < high)
    {
        sum = arr[low] + arr[high];
        if (abs(sum) < abs(ans))
            ans = sum;
        if (sum > 0)
            high --;
        else
            low ++;
    }
    return ans;
}

int main() {
    int cases;
    cin >> cases;
    while (cases --)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << sumCloseToZero(arr, n) << endl;
    }
    return 0;
}
    