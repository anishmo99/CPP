#include <iostream>
#include <stack>
using namespace std;

void printNGE(long long int arr[], int n)
{
    stack<long long int> s;
    long long int storeNGE[n];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        if (s.empty())
            storeNGE[i] = -1;
        else
            storeNGE[i] = s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << storeNGE[i] << " ";
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        long long int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        printNGE(arr, n);
        cout << endl;
    }
    return 0;
}

//inorder but not accepted by gfg compiler, seg fault
/*
#include <iostream>
#include <stack> 
using namespace std; 

void printNGE(int arr[], int n) { 
stack <int> s; 
static int store[10000000000];
s.push(arr[0]); 

for (int i = 1; i < n; i++) { 

	if (s.empty()) { 
	s.push(arr[i]); 
	continue; 
	} 
	while (s.empty() == false && s.top() < arr[i]) 
	{		 
        store[s.top()] = arr[i];
		//cout << s.top() << " --> " << arr[i] << endl; 
		s.pop(); 
	} 

	s.push(arr[i]); 
} 

while (s.empty() == false) {
    store[s.top()]= -1;
	//cout << s.top() << " --> " << -1 << endl; 
	s.pop(); 
} 
//cout<<"checking"<<endl;
for(int i=0;i<n;i++)
{
    cout<<store[arr[i]]<<" ";
}
} 

int main() { 
int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
         printNGE(arr,n); 
         cout<<endl;
    }
    return 0;
}
*/