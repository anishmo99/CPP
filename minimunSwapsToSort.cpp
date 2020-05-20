//
//  minimunSwapsToSort.cpp
//  C++
//
//  Created by Anish Mookherjee on 21/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int minSwaps(int arr[],int n)
{
    
    pair<int,int> arrPos[n];
    
    for(int i=0;i<n;i++)
    {
        arrPos[i].first=arr[i];
        arrPos[i].second=i;
    }
    
    sort(arrPos,arrPos+n);
    
    vector <bool> vis(n,false);
    
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
        
        if(vis[i]||arrPos[i].second==i)
            continue;
        
        int cycle_size=0;
        int j=i;
        
        while(!vis[j])
        {
            vis[j]=true;
            j=arrPos[j].second;
            cycle_size++;
        }
        
        if(cycle_size>0)
            ans+=cycle_size-1;
    }
    
    return ans;

}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<minSwaps(arr,n);
}

