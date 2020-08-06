#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    unordered_set<int> set;
	    for(int i = 0; i < n; i++)
	    {
	        cin>>arr[i];
	        set.insert(arr[i]);
	    }
	    cout<<accumulate(set.begin(), set.end(), 0)<<endl;
	}
	return 0;
}