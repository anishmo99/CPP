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
