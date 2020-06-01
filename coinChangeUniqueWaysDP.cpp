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