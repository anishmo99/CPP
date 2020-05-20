#include <iostream>
using namespace std;

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
        
        for(int i=d;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<d;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
