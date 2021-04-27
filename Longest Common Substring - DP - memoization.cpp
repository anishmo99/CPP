#include<bits/stdc++.h>
using namespace std;

// refer - https://www.youtube.com/watch?v=HrybPYpOvz0&ab_channel=AdityaVerma
// memoization

vector<vector<vector<int>>> dp;

int fun(string &a, string &b, int i, int j,int count)
{
    if(i<0 or j<0) 
    return count;
    
    if(dp[i][j][count]!=-1) 
    return dp[i][j][count];
    
    int num3 = count;
    
    if(a[i]==b[j]) 
    num3 = fun(a,b,i-1,j-1,count+1); // case 1
    
    int num1 = fun(a,b,i,j-1,0); // case 2
    int num2 = fun(a,b,i-1,j,0); // case 3
    
    return dp[i][j][count] = max(num3,max(num1,num2)); // maximum of all 3 cases
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	
	    string a,b;
	    cin>>a>>b;
	    
	    int count = 0;
	    dp.clear();
	    dp.resize(n+1,vector<vector<int>> (m+1,vector<int> (max(n,m)+1,-1)));
	    cout<<fun(a,b,n-1,m-1,count)<<endl;
	}
	
	return 0;
}