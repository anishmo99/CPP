#include <iostream>
#include <vector>
using namespace std;

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
            cin >> arr[i];

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == (i + 1))
            {
                cout << i + 1 << " ";
                flag = true;
            }
        }
        if (!flag)
            cout << "Not Found";
        cout << endl;
    }
    return 0;
}