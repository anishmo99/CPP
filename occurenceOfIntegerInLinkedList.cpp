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
}*head;

int count(struct node* head, int search_for)
{
    int c=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==search_for)
        {
            c++;
        }
        temp=temp->next;
    }
    return c;
}

/* recursion

int count(struct Node* head, int key) 
{ 
    if (head == NULL) 
        return frequency; 
    if (head->data == key) 
        frequency++; 
    return count(head->next, key); 
}
 
*/