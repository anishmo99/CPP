//
//  LeaderInAnArray.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 14/12/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        list<int> l;
        int max=0;
        int c;
        cin>>c;
        int a[c];
        for(int i=0;i<c;i++)
        {
            cin>>a[i];
        }
        max=a[c-1];
        l.push_back(max);
        for(int i=c-2;i>=0;i--)
        {
            if(max>=a[i])
            {
                max=a[i];
                l.push_back(max);
            }
        }
        l.reverse();
        for(int i : l)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
