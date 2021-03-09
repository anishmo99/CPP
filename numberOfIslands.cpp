// BFS

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        int dir[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    islands++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        pair<int, int> temp = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int x = temp.first + dir[k];
                            int y = temp.second + dir[k + 1];
                            if (x < grid.size() and x >= 0 and y < grid[0].size() and y >= 0 and grid[x][y] == '1')
                            {
                                q.push({x, y});
                                grid[x][y] = '0';
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};

// DFS

class Solution
{
public:
    bool isValid(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == '1' && !visited[i][j];
    }

    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;
        vector<pair<int, int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int k = 0; k < offsets.size(); ++k)
        {
            int next_i = i + offsets[k].first;
            int next_j = j + offsets[k].second;
            if (isValid(next_i, next_j, grid, visited))
            {
                dfs(next_i, next_j, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int islands(0);
        if (grid.size() == 0)
        {
            return islands;
        }

        if (grid[0].size() == 0)
        {
            return islands;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(i, j, grid, visited);
                    ++islands;
                }
            }
        }

        return islands;
    }
};