//
//  stackImplementionLinkedList.cpp
//  C++
//
//  Created by Anish Mookherjee on 31/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

void MyStack ::push(int x) {
    StackNode *newNode=(struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data=x;
    if(top==NULL)
    {
        top=newNode;
    }
    else
    {
        newNode->next=top;
        top=newNode;
    }
}

int MyStack ::pop() {
    if(top==NULL)
        return -1;
    StackNode *temp;
    temp=top;
    top=top->next;
    temp->next=NULL;
    return temp->data;
}

