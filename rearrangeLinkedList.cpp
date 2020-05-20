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

#include <vector>
Node *rearrangeEvenOdd(Node *head)
{
    if(head==NULL||head->next==NULL)    return head;
    vector<int> even,odd;
    Node *temp=head;
    while(temp->next&&temp->next->next)
    {
        even.push_back(temp->data);
        temp=temp->next;
        odd.push_back(temp->data);
        temp=temp->next;
    }
    even.push_back(temp->data);
    temp=head;
    for(int i=0;i<even.size();i++)
    {
        temp->data=even[i];
        temp=temp->next;
    }
    for(int i=0;i<odd.size();i++)
    {
       temp->data=odd[i];
       temp=temp->next;
    }
    return head;
}