#include <iostream>
using namespace std;

long long int merge(long long int arr[],long long int temp[],int left,int mid,int right);
long long int mergeSort(long long int arr[],long long int temp[],int left,int right);

long long int countInversions(long long int arr[],int n){
    long long int temp[n];
    return mergeSort(arr,temp,0,n-1);
}

long long int mergeSort(long long int arr[],long long int temp[],int left,int right){
    int mid=0;
    long long int inv_count=0;
    if(right>left){
        mid=(right+left)/2;
        
        inv_count+=mergeSort(arr,temp,left,mid);
        inv_count+=mergeSort(arr,temp,mid+1,right);
        
        inv_count+=merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

long long int merge(long long int arr[],long long int temp[],int left,int mid,int right){
    int i,j,k;
    long long int inv_count=0;
    i=left;
    j=mid;
    k=left;
    
    while(i<=mid-1&&j<=right){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            
            inv_count+=mid-i;
        }
    }
    
    while(i<=mid-1){
        temp[k++]=arr[i++];
    }
    
    while(j<=right)    {
        temp[k++]=arr[j++];
    }
    
    for(int i=left;i<=right;i++)
        arr[i]=temp[i];
        
    return inv_count;
}

int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<countInversions(arr,n)<<endl;
    }
}
