// leetcode

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr)
            return nullptr;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(a!=b){
            a = a==nullptr?headB:a->next;
            b = b==nullptr?headA:b->next;
        }
        
        return a;
    }
};

// gfg

//
//  intersectionPointYLinkedList.cpp
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

int intersectPoint(Node* head1, Node* head2)
{
    Node *a=head1;
    Node *b=head2;
    int alen=0,blen=0,len_diff=0;
    while(a!=NULL)
    {
        a=a->next;
        alen++;
    }
    while(b!=NULL)
    {
        b=b->next;
        blen++;
    }
    a=head1;
    b=head2;
    if(alen>blen)
    {
        len_diff=alen-blen;
        while(len_diff!=0)
        {
            a=a->next;
            len_diff--;
        }
    }
    else
    {
       len_diff=blen-alen;
        while(len_diff!=0)
        {
            b=b->next;
            len_diff--;
        }
    }
    while(a!=NULL && b!=NULL)
    {
        if(a==b)
            return a->data;
        a=a->next;
        b=b->next;
    }
    return -1;
}

