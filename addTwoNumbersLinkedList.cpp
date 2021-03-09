//
//  addTwoNumbersLinkedList.cpp
//  C++
//
//  Created by Anish Mookherjee on 18/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


//time limit exceeds but works properly
/*
Node* addTwoLists(Node* first, Node* second) {
    Node *prev=NULL,*temp;
    Node *res=NULL;
    int carry=0,sum;
    while(first!=NULL || second!=NULL)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        sum=carry+(first?first->data:0)+(second?second->data:0);
        carry=sum>=10?1:0;
        sum%=10;
        temp->data=sum;
        if(res==NULL)
            res=temp;
        else
            prev->next=temp;
        prev=temp;
        if(first) first=first->next;
        if(second) second=second->next;
    }
    temp=(struct Node*)malloc(sizeof(struct Node));
    if(carry>0)
    {
        temp->data=carry;
        prev->next=temp;
    }
    else
        prev->next=NULL;
    return res;
}
*/


//optimised code
Node* addTwoLists(Node* A, Node* B) {
    if(!A) //if(A==NULL)
        return B;
    if(!B)
        return A;
        
    int carry = 0, sum = 0;
    sum = A->data + B->data + carry;
    Node* newHead = new Node(sum%10);
    carry = sum/10;
    A = A->next;
    B = B->next;
    Node* newHeadPtr = newHead;
    
    while(A || B || carry)
    {
        sum = (A ? A->data : 0) + (B ? B->data : 0) + carry;
        Node* temp = new Node(sum%10);
        carry = sum/10;
        newHead->next = temp;
        newHead = newHead->next;
        if(A)
            A = A->next;
        if(B)
            B = B->next;
    }
    
    return newHeadPtr;
}

// or

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode();
        ListNode *ptr = head;

        int sum = 0, carry = 0;

        while (l1 and l2)
        {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode *temp = new ListNode(sum);

            ptr->next = temp;
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *temp = new ListNode(sum);
            ptr->next = temp;
            ptr = ptr->next;
            l1 = l1->next;
        }

        while (l2)
        {
            sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *temp = new ListNode(sum);
            ptr->next = temp;
            ptr = ptr->next;
            l2 = l2->next;
        }

        if (carry)
        {
            ListNode *temp = new ListNode(carry);
            ptr->next = temp;
        }

        return head->next;
    }
};