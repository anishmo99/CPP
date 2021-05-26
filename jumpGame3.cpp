class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(nums.size(), false);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                
                if(nums[cur] == 0)
                    return true;
                
                if(cur + nums[cur] < nums.size() and !visited[cur + nums[cur]]){
                    q.push(cur + nums[cur]);
                    visited[cur + nums[cur]] = true;
                }
                
                if(cur - nums[cur] >= 0 and !visited[cur - nums[cur]]){
                    q.push(cur - nums[cur]);
                    visited[cur - nums[cur]] = true;
                }
            }
        }
        return false;
    }
};