//
//  MergeWithoutExtraSpace.cpp
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
        int x,c1,c2;
        cin>>c1>>c2;
        list<int>l1,l2;
        for(int i=0;i<c1;i++)
        {
            cin>>x;
            l1.push_back(x);
        }
        for(int i=0;i<c2;i++)
        {
            cin>>x;
            l2.push_back(x);
        }
        l1.merge(l2);
        for(int i : l1)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
