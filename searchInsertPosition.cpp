class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        if(target<=nums[i])
            return i;
        if(target>nums[i]&&nums.size()==1)
            return i+1;
        for(i=1;i<nums.size();i++)
        {
            if(target==nums[i]||(target>nums[i-1]&&target<nums[i]))
                return i;
        }
         return i;
    }
};