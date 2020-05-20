class Solution {
public:
    int maxPower(string s) {
        if(s.length()==0)   return 0;
        if(s.length()==1)   return 1;
        int dp[s.length()];
        int max=0;
        for(int i=0;i<s.length();i++)
            dp[i]=1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
                dp[i]=dp[i-1]+1;
            if(max<dp[i])
                max=dp[i];
        }
        return max;
    }
};
