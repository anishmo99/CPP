//
//  MonkAndWelcomeProblem.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 13/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int c[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;i++)
    {
        c[i]=a[i]+b[i];
        cout<<c[i]<<" ";
    }
    return 0;
}
