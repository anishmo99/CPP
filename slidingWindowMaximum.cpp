class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.empty())
            return ans;
        
        deque<int> deque;
        
        for(int i = 0; i < nums.size(); i++){
            while(!deque.empty() and deque.front() <= i - k)
                deque.pop_front();
            
            while(!deque.empty() and nums[deque.back()] <= nums[i])
                deque.pop_back();
            
            deque.push_back(i);
            
            if(i >= k - 1)
                ans.push_back(nums[deque.front()]);
        }
        return ans;
    }
};