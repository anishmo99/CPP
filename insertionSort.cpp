//
//  InsertionSort.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 13/10/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;
void insertionSort(int arr[], int n);
int main()
{
    int i, n;
    cout<<"Enter the number of elements in the array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertionSort(arr, n);
    cout<<"The sorted array is: "<<endl;
    for(i=0;i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}
void insertionSort(int arr[], int n)
{
int i, j, temp;
for(i=1;i<n;i++)
{
    temp = arr[i];
    j = i-1;
    while((temp < arr[j]) && (j>=0))
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
    }
}
