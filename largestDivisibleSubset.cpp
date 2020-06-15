class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        vector<int> sol;
        
        if(nums.empty())
            return sol;
        
        int max_count=1,prev{};
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0&&1+dp[j]>dp[i])
                    dp[i]=dp[j]+1;
                max_count=max(max_count,dp[i]);
            }
        }
        
        prev=-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(dp[i]==max_count&&(prev==-1||prev%nums[i]==0))
            {
                sol.push_back(nums[i]);
                max_count--;
                prev=nums[i];
            }
        }
        
        return sol;
    }
};
