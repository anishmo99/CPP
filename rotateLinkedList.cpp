//
//  rotateLinkedList.cpp
//  C++
//
//  Created by Anish Mookherjee on 18/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//


#include <iostream>

using namespace std;

 struct Node {
 int data;
 struct Node *next;
 Node(int x) {
 data = x;
 next = NULL;
 }
 };

/*  This function should rotate list counter-clockwise
 by k and return new head (if changed) */

Node* rotate(Node* head, int k)
{
    Node *ptr1=head,*ptr2;
    int count=1;
    while(count<k && ptr1!=NULL)
    {
        ptr1=ptr1->next;
        count++;
    }
    if(ptr1==NULL)
        return head;
    ptr2=ptr1;
    while(ptr1->next!=NULL)
    {
        ptr1=ptr1->next;
    }
    ptr1->next=head;
    head=ptr2->next;
    ptr2->next=NULL;
    return head;
}
