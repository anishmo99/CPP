#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkArrayHill(int arr[], int n)
{
    if (n == 1)
        return true;
    int i = 1;
    while (arr[i] > arr[i - 1] && i < n)
        ++i;

    while (arr[i] == arr[i - 1] && i < n)
        ++i;

    while (arr[i] < arr[i - 1] && i < n)
        ++i;

    return (i == n);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (checkArrayHill(arr, n))
        cout << "yes";
    else
        cout << "no";
    return 0;
}

// 1 testcase did not work with the below code
/*
bool checkArrayHill(int arr[], int n)
{
    if(n == 0)
        return false;
    if(n == 1)
        return true;
    
    bool increasing = false, constant = false, decreasing = false;

    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] < arr[i + 1] and constant == false and decreasing == false)
            increasing = true;
        
        else if(arr[i] == arr[i + 1] and decreasing == false)
            constant = true;
        
        else if(arr[i] > arr[i + 1] and constant == true)
            decreasing = true;
        
        else 
            return false;
    }
    return constant == true;
}
*/