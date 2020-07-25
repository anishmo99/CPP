#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void display(vector<int> vmedian)
{
    for (auto median : vmedian)
        cout << median << endl;
}

void findMedianInStream(vector<int> arr, int n)
{
    vector<int> vmedian;
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;

    int median = arr[0];
    vmedian.push_back(median);
    lower.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        int number = arr[i];
        if (lower.size() > higher.size())
        {
            if (number < median)
            {
                higher.push(lower.top());
                lower.pop();
                lower.push(number);
            }
            else
            {
                higher.push(number);
            }
            median = (lower.top() + higher.top()) / 2;
        }
        else if (lower.size() == higher.size())
        {
            if (number < median)
            {
                lower.push(number);
                median = lower.top();
            }
            else
            {
                higher.push(number);
                median = higher.top();
            }
        }
        else
        {
            if (number > median)
            {
                lower.push(higher.top());
                higher.pop();
                higher.push(number);
            }
            else
            {
                lower.push(number);
            }
            median = (lower.top() + higher.top()) / 2;
        }

        vmedian.push_back(median);
    }
    display(vmedian);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    findMedianInStream(arr, n);
    return 0;
}