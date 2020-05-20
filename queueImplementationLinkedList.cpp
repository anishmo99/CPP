//
//  QueueImplementationLinkedList.cpp
//  C++
//
//  Created by Anish Mookherjee on 31/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;


struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};

void MyQueue:: push(int x)
{
    QueueNode *newNode=(struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data=x;
    if(!front) // front==NULL
    {
        front=rear=newNode;
        return;
    }
    rear->next=newNode;
    rear=newNode;
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
    if(!front) //front==NULL
        return -1;
    //IMPORTANT STEP 
    if(!front->next)//front->next==NULL
        rear=NULL;
    QueueNode *temp=front;
    front=front->next;
    temp->next=NULL;
    return temp->data;
}

