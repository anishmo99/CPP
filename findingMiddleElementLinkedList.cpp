//
//  findingMiddleElementLinkedList.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 11/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
}*root,*tail;


int getMiddle(Node *head)
{
    struct Node *temp=head;
    int length=0;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    temp=head;
    for(int i=0;i<(length)/2;i++)
    {
        temp=temp->next;
    }
    return temp->data;
}
