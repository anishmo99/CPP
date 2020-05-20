//
//  divideStringNEqualParts.cpp
//  C++
//
//  Created by Anish Mookherjee on 07/04/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int part_size,n;
    cin>>n;
    char str[100];
    cin>>str;
    if(strlen(str)%n!=0)
        cout<<"cannot be divided into equal parts"<<endl;
    else
    {
        part_size=strlen(str)/n;
        for(int i=0;i<strlen(str);i++)
        {
            if(i%part_size==0)
            {
                cout<<endl;
            }
            cout<<str[i];
        }
    }
}

/*sample input
4
a_simple_divide_string_quest
*/
