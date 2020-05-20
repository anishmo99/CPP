#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head;

int detectLoop(node *head)
{
    struct node *slow=head,*fast=head;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return 1;
        }
    }
    return 0;
}

//counting nodes using no. of nodes in a loop
void removeLoop(node *loop,node *head)
{
    node *ptr1=loop;
    node *ptr2=loop;
    int k=1; //node count
    while(ptr1->next!=ptr2)
    {
        ptr1=ptr1->next;
        k++;
    }
    
    ptr1=ptr2=head;
    
    for(int i=0;i<k;i++)
    {
        ptr2=ptr2->next;
    }
    while(ptr2!=ptr1)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    
    while(ptr2->next!=ptr1)
    {
        ptr2=ptr2->next;
    }
    ptr2->next=NULL;
}

//without counting the no. of nodes in a loop
//better method than the previous one
void detectAndRemoveLoop(node *head)
{
    node *slow=head,*fast=head;
    slow=slow->next;
    fast=fast->next->next;
    while(fast && fast->next)
    {
        if(slow==fast)
            break;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    if(slow==fast)
    {
        slow=head;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}

