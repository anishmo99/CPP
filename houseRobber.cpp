// recursion 
class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int n){
        if(n <= 0)
            return 0;
        
        return dp[n] = max(solve(nums, n - 1), solve(nums, n - 2) + nums[n - 1]);
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size() + 1, 0);
        return solve(nums, nums.size());
    }
};

// dp

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 2)
            return *max_element(nums.begin(), nums.end());
        
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        
        return dp[nums.size() - 1];
    }
};