#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define EB emplace_back
#define PB push_back
#define F first
#define S second


int numberOfCoins(vector<int> coins,int v,int n)
{
    int max=v+1;
    vector<int>dp(v+1,max);
    dp[0]=0;
    for(int i=1;i<=v;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j]<=i)
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
        }
    }
    return dp[v]>v?-1:dp[v];
}


int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   int cases;
   cin >> cases;
   while(cases--){
        int amount;
        cin>>amount;
        int n;
        cin>>n;
        vector<int> coins(n);
        for(int i=0;i<n;i++)
            cin>>coins[i];
        cout<<numberOfCoins(coins,amount,n);
        cout<<endl;
    }
    return 0;
}
