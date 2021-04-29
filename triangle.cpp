class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& triangle, int m, int n){
        if(m == triangle.size() - 1)
            return dp[m][n] = triangle[m][n];
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] = triangle[m][n] + min(solve(triangle, m + 1, n), solve(triangle, m + 1, n + 1));
    }
    int minimumTotal(vector<vector<int>>& triangle){
        dp.resize(triangle.size(), vector<int> (triangle[triangle.size() - 1].size(), -1));
        return solve(triangle, 0, 0);
    }
};