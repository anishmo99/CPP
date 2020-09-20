#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkCon(int arr[], int n){
	if(n < 1)
		return false;

	int min = *min_element(arr, arr + n);
	int max = *max_element(arr, arr + n);
	
	if(max - min + 1 == n){
	    vector<bool> hash(n, false);
		for(int i = 0; i < n; i++){
			if(hash[arr[i] - min] == true)
				return false;
			else
				hash[arr[i] - min] = true;
		}
		return true;
	}
	return false;
}

int main() {
	int cases;
	cin >> cases;
	while(cases--){
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		if(checkCon(arr, n))
		    cout << "Yes" << endl;
		else    
		    cout << "No" << endl;
	}
	return 0;
}