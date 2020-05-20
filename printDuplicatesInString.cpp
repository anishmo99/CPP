//
//  printDuplicatesInString.cpp
//  C++
//
//  Created by Anish Mookherjee on 06/04/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    char str[100];
    cin>>str;
    int n=strlen(str);
    int count[26]={0};
    for(int i=0;i<n;i++)
    {
        count[str[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(count[i]>1)
            cout<<char(i+'a')<<", count "<<count[i]<<endl;
    }
    return 0;
}
