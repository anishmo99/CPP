//
//  list.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 29/11/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> list1, list2;
    int a1[]={5,4,3,2,1};
    int a2[]={6,7,8,9,10};
    for(int i=0;i<5;i++)
    {
        list1.push_back(a1[i]);
        list2.push_back(a2[i]);
    }
    list1.reverse();
    list1.swap(list2);
    list2.merge(list1);
    while(!list2.empty())
    {
        cout<<list2.front()<<endl;
        list2.pop_front();
    }
    return 0;
}
