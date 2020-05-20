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

}*head;


Node* pairWiseSwap(struct Node* head)
{
Node *cur=head;
if(!head || !head->next) return head;
while( cur && cur->next!=NULL)
{

int x=cur->data;
cur->data=cur->next->data;
cur->next->data=x;
cur=cur->next->next;
}
return head;
}