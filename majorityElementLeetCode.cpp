class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
                count++;
            else
            {
                count=1;
            }
            if(count>nums.size()/2)
                return nums[i];
        }
        return nums[nums.size()-1];
    }
};
