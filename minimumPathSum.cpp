// DP

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i = 1; i < c; i++){
            grid[0][i] += grid[0][i - 1];
        }
        
        for(int i = 1; i < r; i++){
            grid[i][0] += grid[i - 1][0];
            for(int j = 1; j < c; j++){
                grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[r - 1][c - 1];
    }
};

// memoization

class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid, int m, int n){
        if(m < 0 or n < 0)
            return INT_MAX;
        
        if(m == 0 and n == 0)
            return dp[m][n] = grid[m][n];
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] = grid[m][n] + min(solve(grid, m - 1, n), solve(grid, m, n - 1));      
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(), vector<int> (grid[0].size(), -1));
        
        return solve(grid, grid.size() - 1, grid[0].size() - 1);
    }
};