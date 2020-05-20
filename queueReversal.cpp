//
//  queueReversal.cpp
//  C++
//
//  Created by Anish Mookherjee on 31/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<long long int> rev(queue<long long int> q)
{
    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}
