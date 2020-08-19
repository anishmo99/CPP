#include <iostream>
using namespace std;

void lengthUnsortedSubarray(int arr[], int n){
	int start = 0, end = n - 1;

	for(start = 0; start < n - 1; start++){
		if(arr[start] > arr[start + 1])
			break;
	}
    
    if(start == n - 1){
        cout << start << " " << end;
        return;
    }
    
	for(end = n - 1; end >= 0; end--){
		if(arr[end] < arr[end - 1])
			break;
	}

	int max = arr[start];
	int min = arr[start];

	for(int i = start + 1; i <= end; i++){
		if(max < arr[i])
			max = arr[i];
		if(min > arr[i])
			min = arr[i];
	}

	for(int i = 0; i < start; i++){
		if(arr[i] > min){
			start = i;
			break;
		}
	}

	for(int i = n - 1; i >= end; i--){
		if(arr[i] < max){
			end = i;
			break;
		}
	}

	cout << start << " " << end;
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

		lengthUnsortedSubarray(arr, n);
		cout << endl;
	}
	return 0;
}

