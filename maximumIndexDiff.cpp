#include <iostream>
#include <vector>
using namespace std;

int maxIndexDiff(vector<long long int> arr, int n)
{
    int maxDiff = 0;
    vector<long long int> left_min(n, 0);
    vector<long long int> right_max(n, 0);

    left_min[0] = arr[0];

    for (int i = 1; i < n; i++)
        left_min[i] = min(left_min[i - 1], arr[i]);

    right_max[n - 1] = arr[n - 1];

    for (int j = n - 2; j >= 0; j--)
        right_max[j] = max(right_max[j + 1], arr[j]);

    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (left_min[i] <= right_max[j])
        {
            maxDiff = max(maxDiff, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }

    return maxDiff;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        vector<long long int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxIndexDiff(arr, n) << endl;
    }
    return 0;
}