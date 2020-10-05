class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int result = 0;

        int row = grid.size(), col = grid[0].size();
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        queue<pair<int, int>> queue;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                    queue.emplace(i, j);
            }
        }

        if (queue.empty())
            result = 1;

        while (!queue.empty())
        {
            int count = queue.size();
            result++;
            while (count--)
            {
                auto [x, y] = queue.front();
                queue.pop();

                for (auto &dir : directions)
                {
                    int a = x + dir[0];
                    int b = y + dir[1];

                    if (a < 0 or b < 0 or a >= row or b >= col or grid[a][b] != 1)
                        continue;

                    grid[a][b] = 2;
                    queue.emplace(a, b);
                }
            }
        }

        for (auto &row : grid)
        {
            for (int x : row)
            {
                if (x == 1)
                    return -1;
            }
        }

        return result - 1;
    }
};