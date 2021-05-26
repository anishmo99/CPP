class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jumps = 0, curend = 0, curfurthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curfurthest = max(curfurthest, i + nums[i]);
            if (i == curend)
            {
                jumps++;
                curend = curfurthest;
            }
        }
        return jumps;
    }
};

// BFS
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return 0;
        
        queue<int> q;
        q.push(0);
        
        int count = 0;
        int start = 0;
        int end = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                
                if(cur >= n - 1)
                    return count;
                
                start = cur;
                end = max(end, cur + nums[cur]);
            }
            
            for(int i = start + 1; i <= end; i++)
                q.push(i);
            
            count++;
        }
        
        return -1;
    }
};