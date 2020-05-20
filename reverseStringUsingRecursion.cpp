//
//  reverseStringUsingRecursion.cpp
//  C++
//
//  Created by Anish Mookherjee on 07/04/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;

void reverse(char str[])
{
    if(strlen(str)==0)
        return;
    reverse(str+1);
    cout<<str[0];
}

int main()
{
    char str[100];
    cin>>str;
    reverse(str);
    return 0;
}
