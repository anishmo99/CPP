class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {

        if (matrix.size() <= 0 || matrix[0].size() <= 0)
            return 0;

        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> heights(c + 1, 0);

        int max_area = 0;

        for (int i = 0; i < r; i++)
        {

            stack<int> stack;

            for (int j = 0; j < c + 1; j++)
            {
                if (j < c)
                {
                    if (matrix[i][j] == '1')
                        heights[j] += 1;
                    else
                        heights[j] = 0;
                }

                while (!stack.empty() and heights[j] < heights[stack.top()])
                {
                    int cur_index = stack.top();
                    stack.pop();

                    int width = stack.empty() ? j : j - 1 - stack.top();

                    max_area = max(max_area, heights[cur_index] * width);
                }

                stack.push(j);
            }
        }
        return max_area;
    }
};