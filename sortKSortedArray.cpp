#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        priority_queue<int, vector<int>, greater<int>> pq(arr, arr + k + 1);

        int index = 0;

        for (int i = k + 1; i < n; i++)
        {
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }

        while (!pq.empty())
        {
            arr[index++] = pq.top();
            pq.pop();
        }

        for (int x : arr)
        {
            cout << x << " ";
        }

        cout << endl;
    }
    return 0;
}