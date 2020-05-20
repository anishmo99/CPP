#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    if(x==1)
        return head->next;
    Node *cur=head,*prev;
    for(int i=1;i<x;i++)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    free(cur);
    return head;
}
