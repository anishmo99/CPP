class Solution {
public:
    vector<vector<int>> dp;
    int fun(vector<int> arr, int total, int target, int cursum, int n){
        if(n == 0){
            if(cursum - (total - cursum) == target)
                return 1;
            return 0;
        }
        
        if(dp[n][cursum] != -1)
            return dp[n][cursum];
        
        if(arr[n - 1] <= cursum)
            return dp[n][cursum] = fun(arr, total, target, cursum - arr[n - 1], n - 1) + fun(arr, total, target, cursum, n - 1);
        else
            return dp[n][cursum] = fun(arr, total, target, cursum, n - 1);
}
    int findTargetSumWays(vector<int>& nums, int S) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        
        dp.clear();
        dp.resize(n + 1, vector<int> (total + 1, -1));
        
        return fun(nums, total, S, total, n);
    }
};