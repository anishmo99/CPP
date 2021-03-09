class Solution
{
public:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &seen)
    {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or seen[i][j] or grid[i][j] == 0)
            return 0;

        seen[i][j] = true;

        return (1 + dfs(i + 1, j, grid, seen) + dfs(i, j + 1, grid, seen) + dfs(i - 1, j, grid, seen) + dfs(i, j - 1, grid, seen));
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 and !seen[i][j])
                {
                    ans = max(ans, dfs(i, j, grid, seen));
                }
            }
        }

        return ans;
    }
};