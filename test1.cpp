#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;

#define EB emplace_back
#define PB push_back
#define F first
#define S second


int numberOfCoins(vector<int> coins,int amount,int n)
{
    int dp[amount][n];

    for(int i=0;i<n;i++)
        dp[0][i]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(i==0)

        }
    }

}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

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
            cin>>v[i];
        cout<<numberOfCoins(coins,amount,n);
        cout<<endl;
    }
    return 0;
}
