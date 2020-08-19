class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size(), start = 0, end = n - 1;
        
        for(start = 0; start < n - 1; start++){
            if(nums[start] > nums[start + 1])
                break;
        }
        
        if(start == n - 1)
            return 0;
        
        for(end = n - 1; end > 0; end--){
            if(nums[end] < nums[end - 1])
                break;
        }
        
        int min = nums[start];
        int max = min;
        
        for(int i = start + 1; i <= end; i++){
            if(nums[i] > max)
                max = nums[i];
            if(nums[i] < min)
                min = nums[i];
        }
        
        
        for(int i = 0; i < start; i++){
            if(nums[i] > min){
                start = i;
                break;
            }
        }
        
        for(int i = n - 1; i > end; i--){
            if(nums[i] < max){
                end = i;
                break;
            }
        }
        
        return end - start + 1;
    }
};