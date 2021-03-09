class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        if (heights.empty())
            return 0;

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

        return max_area;
    }
};