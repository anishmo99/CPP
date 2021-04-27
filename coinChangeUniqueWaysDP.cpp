// memoization

class Solution
{
  public:
    vector<vector<long long int>> dp;
    long long int fun(int arr[], int n, int coin){
        if(coin == 0)
            return 1;
            
        if(n == 0)
            return 0;
            
        if(dp[n][coin] != -1)
            return dp[n][coin];
            
        if(arr[n - 1] <= coin){
            return dp[n][coin] = fun(arr, n, coin - arr[n - 1]) + fun(arr, n - 1, coin);
        }
        
        else
            return dp[n][coin] = fun(arr, n - 1, coin);
    }
    long long int count( int arr[], int n, int sum)
    {
        dp.clear();
        dp.resize(n + 1, vector<long long int> (sum + 1, -1));
        
        return fun(arr, n, sum);
    }
};

// TOP DOWN

#include <cstring>
#include <iostream>
using namespace std;

int coinChange(int arr[],int amount,int n)
{
    int temp[n+1][amount+1];
    memset(temp,0,sizeof(temp));
    
    for(int i=0;i<=n;i++)
        temp[i][0]=1;
        
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=amount;j++)
        {
            if(j<arr[i-1])
            {
                temp[i][j]=temp[i-1][j];
            }
            else
            {
                temp[i][j]=temp[i-1][j]+temp[i][j-arr[i-1]];
            }
        }
    }
    return temp[n][amount];
}
int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    int amount;
	    cin>>amount;
	        
	    cout<<coinChange(arr,amount,n);
	    cout<<endl;
	}
	return 0;
}