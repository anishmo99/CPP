#include <iostream>
using namespace std;

void reverseArr(int arr[],int low,int high)
{
    while(low<high)
    {
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        high--;
        low++;
    }
}

void leftRotate(int arr[],int n,int d)
{
    if(d==0)    return ;
    reverseArr(arr,0,d-1);
    reverseArr(arr,d,n-1);
    reverseArr(arr,0,n-1);
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int d;
        cin>>d;
        leftRotate(arr,n,d);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}

