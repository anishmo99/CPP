class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> sol;
        int count=0,i=0;
        sort(nums.begin(),nums.end());
        while(i<nums.size()-1&&count<=2)
        {
            if(nums[i]!=nums[i+1])
            {
                count++;
                sol.push_back(nums[i]);
                i++;
            }
            else
                i+=2;
        }
        if(count<2)
            sol.push_back(nums[nums.size()-1]);
        return sol;
    }
};
