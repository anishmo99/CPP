#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int cases;
    cin >> cases;

    while (cases--)
    {
        int n;
        cin >> n;

        vector<int> heights(n);

        for (int i = 0; i < n; i++)
            cin >> heights[i];

        heights.push_back(0);

        int max_area = heights[0];

        stack<int> stack;
        stack.push(0);

        for (int i = 1; i < heights.size(); i++)
        {
            while (!stack.empty() and heights[i] < heights[stack.top()])
            {
                int cur_index = stack.top();
                stack.pop();

                int width = stack.empty() ? i : i - 1 - stack.top();

                max_area = max(max_area, heights[cur_index] * width);
            }
            stack.push(i);
        }

        cout << max_area << endl;
    }
    return 0;
}