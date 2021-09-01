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