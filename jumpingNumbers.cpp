class Solution {
  public:
    long long jumpingNums(long long X) {
        queue<long long> q;
        for(int i = 1; i <= 9; i++)
            q.push(i);
            
        long long ans = 0;
        
        while(!q.empty()){
            long long cur = q.front();
            q.pop();
            
            if(cur <= X)
                ans = cur;
            
            if(cur > X)
                continue;
                
            long long lastdig = cur % 10;
            
            if(lastdig == 0)
                q.push((cur * 10) + (lastdig + 1));
                
            else if(lastdig == 9)
                q.push((cur * 10) + (lastdig - 1));
                
            else{
                q.push((cur * 10) + (lastdig - 1));
                q.push((cur * 10) + (lastdig + 1));
            }
        }
        
        return ans;
    }
};