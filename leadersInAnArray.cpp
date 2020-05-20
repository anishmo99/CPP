#include <iostream>
using namespace std;

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int max=arr[n-1];
		cout<<max<<" ";
		for(int i=n-2;i>=0;i--)
		{
			if(max<arr[i])
			{
				max=arr[i];
				cout<<max<<" ";
			}
		}
		cout<<endl;
	}
}