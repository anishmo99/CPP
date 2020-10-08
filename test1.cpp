#include <iostream>
using namespace std;

void zeros_end(int arr[], int n)
{
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0 and i < j)
        {
            swap(arr[i], arr[j]);
            j--;
        }
    }

    // return arr;
}

int main()
{
    int n, i, size;
    cin >> n;
    int arr[n];

    for (i = 0; i < n; i++)
        cin >> arr[i];

    zeros_end(arr, n);

    for(auto i : arr)
        cout << i << " ";

    return 0;
}