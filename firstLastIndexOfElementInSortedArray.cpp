#include <iostream>
using namespace std;

void findRange(int arr[],int n,int target)
{
    int first,second,flag=0;
    for(int i{};i<n;i++)
    {
        if(arr[i]==target&&flag==0)
        {
            flag=1;
            first=i;
            second=i;
        }
        else if(arr[i]==target&&flag==1)
        {
            second=i;
        }
    }
    if(flag==0)
    {
        cout<<-1;
        return;
    }
    cout<<first<<" "<<second;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        int target;
        int n;
        cin>>n>>target;
        int arr[n];
        for(int i{};i<n;i++)
            cin>>arr[i];
        findRange(arr,n,target);
        cout<<endl;
    }
    return 0;
}
