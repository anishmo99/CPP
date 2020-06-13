#include <iostream>
#include <algorithm>
using namespace std;

bool isPythTrip(int arr[],int n)
{
    for(int i{};i<n;i++)
    {
        arr[i]=pow(arr[i],2);
    }
    sort(arr,arr+n);
    for(int i=n-1;i>=0;i--)
    {
        int l=0;
        int r=i-1;
        while(l<r)
        {
            if(arr[l]+arr[r]==arr[i])
                return true;
            if(arr[l]+arr[r]<arr[i])
                l++;
            else
                r--;
        }
    }
    return false;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i{};i<n;i++)
            cin>>arr[i];
        if(isPythTrip(arr,n))
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    return 0;
}