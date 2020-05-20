class Solution {
public:
    int gcd(int a,int b)
    {
        return b?gcd(b,a%b):a;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(gcd(i,j)==1)
                {
                    ans.push_back(to_string(j)+'/'+to_string(i));
                }
                else
                    continue;
            }
        }
        return ans;
    }
};
