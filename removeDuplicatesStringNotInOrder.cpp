//
//  removeDuplicatesStringNotInOrder.cpp
//  C++
//
//  Created by Anish Mookherjee on 06/04/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

string remDup(string str)
{
    sort(str.begin(),str.end());
    auto res=unique(str.begin(),str.end());
    str=string(str.begin(),res);
    return str;
}

int main()
{
    string str;
    cin>>str;
    cout<<remDup(str)<<endl;
}
