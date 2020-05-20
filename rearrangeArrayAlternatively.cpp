//
//  RearrangeArrayAlternatively.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 14/12/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int c,x,i,j;
        cin>>c;
        vector<int>v;
        for(i=0;i<c;i++)
        {
            cin>>x;
            v.push_back(x);
        }
        i=0;
        j=c-1;
        while(i<j)
        {
            cout<<v[j--]<<" "<<v[i++]<<" ";
        }
        if(i==j)
        cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}
