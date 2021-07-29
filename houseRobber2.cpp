class Solution {
public:
    
    vector<vector<int>> dp;
    
    int fun(vector<int> v,int i, bool last)
    {   
        if(i<0)
            return 0;
                
        if(dp[i][last]!=-1)
            return dp[i][last];
        
        int num1 = 0;
        int num2 = 0;

        if(i==v.size()-1)
            num1 = fun(v,i-2,1) + v[i];    

        else if(i==0)
        {
            if(last==0)
            num1 = fun(v,i-2,last) + v[i];
        }
            
        else
            num1 = fun(v,i-2,last) + v[i];
        
        
        num2 = fun(v,i-1,last);
        
        return dp[i][last] = max(num1,num2);
    }
    
    int rob(vector<int>& v) 
    {
        int n=v.size();
        
        bool last = 0;
        
        dp.clear();
        dp.resize(n+1,vector<int> (2,-1));
        
        return fun(v,n-1,last);
    }
};