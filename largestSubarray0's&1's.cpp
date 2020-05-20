//
//  LargestSubarray0's&1's.cpp
//  C++
//
//  Created by Anish Mookherjee on 19/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;

//O(n^2) time limit exceeds
int maxLen(int arr[], int n) {
    int max=0, sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum=(arr[i]==0)?-1:1;
        for(int j=i+1;j<n;j++)
        {
            (arr[j]==0)?(sum+=-1):(sum+=1);
            if(max<j-i+1&&sum==0)
            {
                max=j-i+1;
            }
        }
    }
    return max;
}


