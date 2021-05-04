class Solution
{
public:
    int numSquares(int n)
    {
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = i;
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};

// memoization - same intuition as min ways to coin change

class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int>& arr, int sum, int n){
        if(sum == 0)
            return dp[sum][n] = 0;
        
        if(n <= 0 or sum < 0)
            return 100000;
        
        if(dp[sum][n] != -1)
            return dp[sum][n];
        
        if(arr[n - 1] <= sum){
            return dp[sum][n] = min(1 + solve(arr, sum - arr[n - 1], n), solve(arr, sum, n - 1));
        }
        else
            return dp[sum][n] = solve(arr, sum, n - 1);
    }
    
    int numSquares(int sum) {
        vector<int> arr;
        for(int i = 0; i < sqrt(sum); i++){
            arr.push_back((i + 1) * (i + 1));
        }
        
        dp.clear();
        dp.resize(sum + 1, vector<int> (arr.size() + 1, -1));
        
        return solve(arr, sum, arr.size());
    }
};