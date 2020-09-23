class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return string();

        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        // memset(dp, 0, sizeof(dp));

        int start = 0, max_length = 1;

        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = true;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                max_length = 2;
            }
        }

        for (int k = 3; k <= s.length(); k++)
        {
            for (int i = 0; i <= s.length() - k; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] and dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    if (k > max_length)
                    {
                        start = i;
                        max_length = k;
                    }
                }
            }
        }

        return s.substr(start, max_length);
    }
};


 //geeksforgeeks

#include <iostream>
#include <cstring>
using namespace std;

string longestPalindrome(string s)
{
    if(s=="")   return "";
    int n=s.length();
    int flag=0;
    bool dp[n][n];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n;i++)
        dp[i][i]=true;
    
    int start=0,maxlength=1;
    for(int i=0;i<n-1;i++)
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=true;
            if(flag==0)
            {
                start=i;
                maxlength=2;
                flag++;
            }
        }
    
    for(int k=3;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j=i+k-1;
            if(s[i]==s[j]&&dp[i+1][j-1]==true)
            {
                dp[i][j]=true;
                if(k>maxlength)
                {
                    maxlength=k;
                    start=i;
                }
            }
        }
    }
    string res=s.substr(start,maxlength);
    return res;
}

 int main() {
     int cases;
     cin>>cases;
     while(cases--)
     {
         string s;
         cin>>s;
         cout<<longestPalindrome(s)<<endl;
     }
     return 0;
 }