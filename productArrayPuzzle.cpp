#include <iostream>
using namespace std;

void prodOfArrExceptSelf(int arr[], int n)
{
    int left_prod[n], right_prod[n];

    left_prod[0] = 1;
    right_prod[n - 1] = 1;

    for (int i = 1; i < n; i++)
        left_prod[i] = left_prod[i - 1] * arr[i - 1];

    for (int i = n - 2; i >= 0; i--)
        right_prod[i] = right_prod[i + 1] * arr[i + 1];

    for (int i = 0; i < n; i++)
        cout << left_prod[i] * right_prod[i] << " ";
}

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
        {
            cin >> arr[i];
        }
        prodOfArrExceptSelf(arr, n);
        cout << endl;
    }
    return 0;
}