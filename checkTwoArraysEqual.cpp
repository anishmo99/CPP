#include <iostream>
#include <unordered_map>
using namespace std;

bool isSame(long long int arr1[],long long int arr2[],int n)
{
    unordered_map<long long int,long long int> ump1,ump2;
    for(int i{};i<n;i++)
    {
        ump1[arr1[i]]++;
        ump2[arr2[i]]++;
    }
    if(ump1==ump2)
        return true;
    return false;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        long long int arr1[n];
        for(int i{};i<n;i++)
            cin>>arr1[i];
        long long int arr2[n];
        for(int i{};i<n;i++)
            cin>>arr2[i];
        cout<<isSame(arr1,arr2,n)<<endl;
    }
    return 0;
}
