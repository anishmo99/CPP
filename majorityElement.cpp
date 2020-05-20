//
//  majorityElement.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 13/12/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAX 1000007
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int c;
        cin>>c;
        int a[MAX]={0},b,flag=0;
        for(int i=0;i<c;i++)
        {
            cin>>b;
            a[b]++;
        }
        for(int i=0;i<c;i++)
        {
            if(a[i]>(c/2))
            {
                cout<<i<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
        cout<<"-1"<<endl;
    }
    return 0;
}
