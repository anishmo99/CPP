//
//  equilibriumPoint.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 05/12/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//sum decreases from left

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int c;
        cin>>c;
        int a[c];
        int sum=0,lsum=0;
        for(int i=0;i<c;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=0;i<c;i++)
        {
            sum-=a[i];
            if(sum==lsum)
            {
                cout<<(i+1)<<endl;
                break;
            }
                lsum+=a[i];
        }
        if(sum!=lsum)
            cout<<-1<<endl;
    }
    return 0;
}
