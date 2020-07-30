#include <iostream>
#include <vector>
using namespace std;

void function(vector<int> arr, int n, int sum)
{
    int low = 0;
    int high = n - 1;

    bool flag = false;
    while (low < high)
    {
        if (arr[low] + arr[high] == sum)
        {
            flag = true;
            cout << arr[low] << " " << arr[high] << " " << sum << endl;
            high--;
            low++;
        }
        else if (arr[low] + arr[high] > sum)
            high--;
        else
            low++;
    }
    if (!flag)
        cout << -1 << endl;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int sum;
        cin >> sum;
        function(arr, n, sum);
        // cout<<endl;
    }
    return 0;
}