#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while(cases --)
	{
	    int n1, n2;
	    cin >> n1 >> n2;
	    int arr1[n1], arr2[n2];
	    unordered_set<int> set;
	    
	    for(int i = 0; i < n1; i++)
	    {
	        cin >> arr1[i];
	        set.insert(arr1[i]);
	    }
	    for(int i = 0; i < n2; i++)
	    {
	        cin >> arr2[i];
	        if(set.find(arr2[i]) == set.end())
	            set.insert(arr2[i]);
	    }
	    cout << set.size() << endl;
	}
	return 0;
}