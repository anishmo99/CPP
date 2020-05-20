//
//  reverseFirstKElementsQueue.cpp
//  C++
//
//  Created by Anish Mookherjee on 31/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#define ll long long
using namespace std;

queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack<ll> s;
    queue<ll> cq;
    int size=q.size();
    for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++)
    {
        cq.push(s.top());
        s.pop();
    }
    for(int i=k;i<size;i++)
    {
        cq.push(q.front());
        q.pop();
    }
    return cq;
}