class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int highest = nums[n - 1], lowest = nums[0];
        
        int ans = highest - lowest;
        
        for(int i = 0; i < n - 1; i++){
            int mini = min(lowest + k, nums[i + 1] - k);
            int maxi = max(highest - k, nums[i] + k);
            ans = min(ans, maxi - mini);
        }
        
        return ans;
        
    }
};