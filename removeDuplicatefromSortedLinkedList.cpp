//
//  removeDuplicatefromSortedLinkedList.cpp
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

Node *removeDuplicates(Node *root)
{
    Node *temp=root;
    Node *next_next;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
         {
             next_next=temp->next->next;
             free(temp->next);
             temp->next=next_next;
         }
        else
            temp=temp->next;
    }
    return root;
}
