#include <iostream>
using namespace std;

int maxSumSubArr(int arr[],int n)
{
    int max_current=arr[0];
    int max_global=arr[0];
    for(int i=1;i<n;i++)
    {
        max_current=max(arr[i],max_current+arr[i]);
        if(max_current>max_global)  max_global=max_current;
        }
        return max_global;
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
	    {
	        cin>>arr[i];
	    }
       cout<<maxSumSubArr(arr,n)<<endl;
	}
	return 0;
}