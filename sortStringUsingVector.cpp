//
//  sortStringUsingVector.cpp
//  C++
//
//  Created by Anish Mookherjee on 19/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char s[20];
    cin>>s;
    sort(s,s+strlen(s));
    cout<<s;
}
