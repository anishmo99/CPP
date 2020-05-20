//
//  removeDuplicateUnsortedLinkedList.cpp
//  C++
//
//  Created by Anish Mookherjee on 30/03/20.
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

Node * removeDuplicates( Node *head)
{
    Node *ptr1=head;
    Node *ptr2,*dup;
    while(ptr1!=NULL)
    {
        ptr2=ptr1;
        while(ptr2->next!=NULL)
        {
            if(ptr1->data==ptr2->next->data)
            {
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(dup);
            }
            else
                ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return head;
}

/*
 Node * removeDuplicates( Node *head)
 {
     Node *ptr1=head;
     Node *ptr2,*dup;
     while(ptr1!=NULL)
     {
         ptr2=ptr1;
         while(ptr2->next!=NULL)
         {
             if(ptr1->data==ptr2->next->data)
             {
                 dup=ptr2->next;
                 ptr2->next=ptr2->next->next;
                 delete(dup);
             }
             else
                 ptr2=ptr2->next;
         }
         ptr1=ptr1->next;
     }
     return head;
 }
 */
