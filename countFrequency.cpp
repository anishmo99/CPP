//
//  CountFrequency.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 20/10/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int i,n;
    cout<<"Enter no. of elements you want to enter."<<endl;
    cin>>n;
    int a[n];
    int b[9];
    cout<<"Enter elements."<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
   int max=0,pos=0;
    for(i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
       {
           if(max<b[j])
           {
               max=b[j];
               pos=j;
               b[j]=0;
           }
       }
       if(max!=0)
           for(int k=0;k<max;k++)
               cout<<max<<endl;
    }
    return 0;
}
