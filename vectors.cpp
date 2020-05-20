//
//  StandardTemplateLibrary.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 28/11/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    v[0]=5;
    v[2]=35;
    v.push_back(40);
    v.insert(v.begin()+2,25);
    cout<<endl;
    while(!v.empty())
    {
        cout<<v.back()<<endl;
        v.pop_back();
    }
    return 0;
}
