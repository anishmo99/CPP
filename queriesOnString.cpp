#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        string str;
        cin>>str;
        int len=str.length();
        int dp[len][26];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<26;j++)
            {   
               if(i>0)
                dp[i][j]+=dp[i-1][j]; 
            }
            dp[i][(str[i]-'a')]++;
        }
        int q;
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            int count=0;
            for(int i=0;i<26;i++)
            {
                if(l>0)
                {
                if(dp[r][i]-dp[l-1][i]>0)
                    count++;
                }
                else
                {
                    if(dp[r][i]>0)
                        count++;
                }
            }
            cout<<count<<" ";
            
        }
        cout<<endl;
    }
    return 0;
}