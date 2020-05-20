#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    int count=0;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        if(x==0)
	            count++;
	    }
        for(int i=0;i<count;i++)
        {
            v[i]=0;
        }
        for(int i=count;i<n;i++)
        {
            v[i]=1;
        }
	    for(int i=0;i<n;i++)
	    {
	        cout<<v[i]<<" ";
	    }
	    cout<<endl;
    }
	return 0;
}