#include <iostream>
#include <stack> 
using namespace std; 

void printNGE(int arr[], int n) 
{ 
    stack<int> s; 
    s.push(arr[0]); 
    for (int i=1;i<n;i++)
    { 
	    if (s.empty())
	    { 
	        s.push(arr[i]); 
	        continue; 
	    }    
    	while (s.empty()==false &&s.top()<arr[i]) 
    	{		 
	    	cout<<arr[i]<<" "; 
		    s.pop(); 
	    } 
	    s.push(arr[i]); 
    }       
    while (s.empty()==false) 
    { 
	    cout<<-1<<" "; 
	    s.pop(); 
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

