#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getMinSquare(int n){
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    
    for(int i=4;i<=n;i++){
        dp[i]=i;
        for(int j=1;j<=sqrt(n);j++){
            int temp=j*j;
            if(temp>i)
                break;
            else
                dp[i]=min(dp[i],1+dp[i-temp]);
        }
    }
    return dp[n];
}

int main() {
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        cout<<getMinSquare(n)<<endl;
    }
    return 0;
}

