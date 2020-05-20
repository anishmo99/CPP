//
//  removeDuplicatesString.cpp
//  C++
//
//  Created by Anish Mookherjee on 06/04/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char *remDup(char str1[],int len)
{
    int index=0;
    for(int i=0;i<len;i++)
    {
        int j;
        for(j=0;j<i;j++)
        {
            if(str1[i]==str1[j])
                break;
        }
        
        if(j==i)
            str1[index++]=str1[i];
    }
    return str1;
}

int main()
{
    char str1[100];
    cin>>str1;
    int len = sizeof(str1) / sizeof(str1[0]);
    cout<<remDup(str1,len)<<endl;
    return 0;
}
