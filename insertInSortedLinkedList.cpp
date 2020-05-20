#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};

void sortedInsert(struct node** head_ref, int data) {
    node *temp=*head_ref,*prev=NULL,*newNode=new node(data);
    if(temp==NULL)  return;
    while(temp!=NULL)
    {
        if(temp->data>data)
            break;
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)
    {
        newNode->next=*head_ref;
        *head_ref=newNode;
        return;
    }
    else if(temp==NULL)
    {
        prev->next=newNode;
        return;
    }
    else
    {
        newNode->next=prev->next;
        prev->next=newNode;
        return;
    }
}