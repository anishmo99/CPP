#include <iostream>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};
 
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* A, SinglyLinkedListNode* B)
{
    if(!A)
        return B;
    if(!B)
        return A;
        
    SinglyLinkedListNode *res = new SinglyLinkedListNode(0); // Don't do ListNode* res = NULL; *resPtr or 
    SinglyLinkedListNode *resPtr = res;          // filling the list gives segmentation fault.
    while(A && B)
    {
        if(A->data <= B->data)
        {
            res->next = A;
            A = A->next;
        }
        else
        {
            res->next = B;
            B = B->next;
        }
        res = res->next;
    }
    
    while(A)
    {
        res->next = A;
        res = res->next;
        A = A->next;
    }
    while(B)
    {
        res->next = B;
        res = res->next;
        B = B->next;
    }
    return resPtr->next;
}


/*struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* sortedMerge(Node* head1,   Node* head2)
{
    Node *head=NULL;
    if(head1->data<head2->data)
    {
        head=head1;
        head1=head1->next;
        head->next=NULL;
    }
    else
    {
        head=head2;
        head2=head2->next;
        head->next=NULL;
    }
    Node *tail=head;
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data<=head2->data)
        {
            tail->next=head1;
            tail=head1;
            head1=head1->next;
            tail->next=NULL;
        }
        else
        {
            tail->next=head2;
            tail=head2;
            head2=head2->next;
            tail->next=NULL;
        }
    }
    if(head1==NULL&&head2!=NULL)
    {
        tail->next=head2;
        return head;
    }
    else if(head2==NULL&&head1!=NULL)
    {
        tail->next=head1;
        return head;
    }
    else
    {
        return head;
    }
}*/

