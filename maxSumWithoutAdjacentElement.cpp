#include <iostream>
using namespace std;

int maxSumWithoutAdjacent(int arr[],int n){
    int incl=arr[0];
    int excl=0,excl_new;
    for(int i=1;i<n;i++){
        excl_new=max(excl,incl);
        incl=excl+arr[i];
        excl=excl_new;
    }
    return max(incl,excl);
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
        cout<<maxSumWithoutAdjacent(arr,n)<<endl;
    }
    return 0;
}
