#include <iostream>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int jumps = 0, curend = 0, curfurthest = 0;

        for (int i = 0; i < n - 1; i++)
        {
            curfurthest = max(curfurthest, i + arr[i]);
            if (i == curend)
            {
                jumps++;
                curend = curfurthest;
            }
        }

        if (curend < n - 1)
            cout << -1;
        else
            cout << jumps;

        cout << endl;
    }
    return 0;
}