#include <iostream>
#include <algorithm>

using namespace std;

bool checkTriplet(int arr[], int n, int target)
{
    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int sum = arr[i] + arr[l] + arr[r];
            if (sum == target)
            {
                return true;
            }
            else if (sum < target)
                l++;
            else
                r--;
        }
    }
    return false;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n, target;
        cin >> n >> target;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << checkTriplet(arr, n, target) << endl;
    }
    return 0;
}