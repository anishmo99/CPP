class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (1001, 1));
        
        int ans = 1;                    
        
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j] + 500;
                
                 if(dp[i][diff] < dp[j][diff] + 1){
                     dp[i][diff] = dp[j][diff] + 1;
                 }
                
                ans = max(ans, dp[i][diff]);
            }
        }
    
        return ans;

    }
};

// or 

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), ret = 2;
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        
        for (int i = 1; i < n; ++i) {
            int curNum = A[i];
            for (int j = 0; j < i; ++j) {
                int diff = curNum - A[j];
                if (dp[j].find(diff) == dp[i].end()) {
                    dp[i][diff] = 2;
                } else {
                    dp[i][diff] = dp[j][diff] + 1;
                    ret = max(ret, dp[i][diff]);
                }
            }
        }
        
        return ret;
    }
};