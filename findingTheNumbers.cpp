#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        n = (2 * n) + 2;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int flag = 0;
        for (int i = 0; i < n - 1;)
        {
            if (arr[i] == arr[i + 1])
            {
                i += 2;
                continue;
            }
            else
            {
                cout << arr[i] << " ";
                flag++;
                i++;
            }
        }
        if (flag != 2)
            cout << arr[n - 1];
        cout << endl;
    }
    return 0;
}