class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;)
        {  if(nums[i]!=nums[i+1])
                return nums[i];
            i+=2;
        }
        return nums[nums.size()-1];
    }
};
