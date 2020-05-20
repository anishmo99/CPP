//
//  SortArray012.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 05/12/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

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
        for(int i=0;i<c;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<c;i++)
        {
            for(int j=i+1;j<c;j++)
            {
                if(a[i]>a[j])
                {
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        for(int i=0;i<c;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
