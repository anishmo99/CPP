#include <iostream>
using namespace std;

void twoRepeatedElements(int arr[], int n)
{
	for(int i = 0; i < n + 2; i++)
	{
		if(arr[abs(arr[i])] > 0)
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		else
			cout << abs(arr[i]) << " ";
	}
}

int main() {
	int cases;
	cin >> cases;
	while(cases --){
		int n;
		cin >> n;
		int arr[n + 2];
		for(int i = 0; i < n + 2; i++)
			cin >> arr[i];
		twoRepeatedElements(arr, n);
		cout << endl;
	}
	return 0;
}