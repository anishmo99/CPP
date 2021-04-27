class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i, j;
        i = 0;
        j = i + 1;
        
        while(i < nums.size()){
            j = i + 1;
            while(j < nums.size() and nums[i] != nums[j]){
                j++;
            }
            
            if(nums[i] == nums[j])
                return nums[i];
            i++;
        }
        return nums[nums.size() - 1];
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[abs(nums[i])] < 0)
                return abs(nums[i]);
            
            nums[abs(nums[i])] = -1 * nums[abs(nums[i])];
        }
        return nums[n - 1];
    }
};