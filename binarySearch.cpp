//
//  BinarySearch.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 14/10/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
    if(l<=r)
    {
        int mid=l+(r-l)/2;
        if(x==arr[mid])
        {
            return mid;
        }
        if(x<arr[mid])
        {
            return binarySearch(arr, l, mid-1, x);
        }
        if(x>arr[mid])
        {
            return binarySearch(arr, mid+1, r, x);
        }
    }
    return -1;
}
void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"displaying elements."<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int n;
    cout<<"How many elements do you want to enter?"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements one by one."<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    cout<<"Enter the element you want to search."<<endl;
    int search;
    cin>>search;
    int result=binarySearch(arr,0,n-1,search);
    if(result==-1)
        cout<<"Element not found."<<endl;
    else
        cout<<"Element found."<<endl;
    return 0;
}
