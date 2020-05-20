#include <iostream>
#include <stack>
using namespace std;

void maxSumSubArr(int arr[],int n, int k)
{
    int max_upto[n];
    stack<int> s;
    s.push(0);

    for(int i=1;i<n;i++)
    {
        while(!s.empty()&&arr[s.top()]<arr[i])
        {
            max_upto[s.top()]=i-1;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty())
    {
        max_upto[s.top()]=n-1;
        s.pop();
    }

    int j=0;
    for(int i=0;i<=n-k;i++)
    {
        while(j<i||max_upto[j]<i+k-1)
            j++;
        
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        maxSumSubArr(arr,n,k);
    }
    return 0;
}

/*
OUTPUT
1
9 3 
9 7 2 4 6 8 2 1 5

ANSWER : 9 7 6 8 8 8 5 
*/