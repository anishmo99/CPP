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
	    vector<int>v1;
	    vector<int>v2;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        v1.push_back(x);
	    }
	    for(int i=0;i<n;i++)
	     {
	        int x;
	        cin>>x;
	        v2.push_back(x);
	    }
	    //sort(v1.begin(), v1.end()); 
        //sort(v2.begin(), v2.end()); 
        vector<int>v3(n*2);
	    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	    int sum=v3[(v3.size()/2)-1]+v3[v3.size()/2];
	    cout<<sum<<endl;
	    //for(auto i:v3)
	      //  cout<<i<<" ";
	}
	return 0;
}