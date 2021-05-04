class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& arr, int m, int n){
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(arr[m][n] == 1)
            return dp[m][n] = 0;
        
        if(m == 0 and n == 0)
            return dp[m][n] = 1;
        
        if(m == 0)
            return dp[m][n] = solve(arr, m, n - 1);
        
        if(n == 0)
            return dp[m][n] = solve(arr, m - 1, n);
        
        if(arr[m][n] != 1)
            return dp[m][n] = solve(arr, m - 1, n) + solve(arr, m, n - 1);
        
        return dp[m][n] = 0;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        
        dp.assign(m, vector<int> (n, -1));
        
        return solve(arr, m - 1, n - 1);
    }
};

// dp in input array

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& dp) {
        int m = dp.size();
        int n = dp[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] == 1){
                    dp[i][j] = 0;
                }
                
                else if(i == 0 and j == 0){
                    dp[i][j] = 1;
                }
             
                else if(i == 0){
                    dp[i][j] = dp[i][j - 1];
                }
                
                else if(j == 0){
                    dp[i][j] = dp[i - 1][j];
                }
                
                else if(dp[i][j] != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};