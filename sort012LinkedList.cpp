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

// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    int count0=0,count1=0,count2=0;
    Node *temp=head;
    while(temp)
    {
        if(temp->data==0)
            count0++;
        if(temp->data==1)
            count1++;
        if(temp->data==2)
            count2++;
        temp=temp->next;
    }
    temp=head;
    for(int i=0;i<count0;i++)
    {
        temp->data=0;
        temp=temp->next;
    }
    for(int i=0;i<count1;i++)
    {
        temp->data=1;
        temp=temp->next;
    }
    for(int i=0;i<count2;i++)
    {
        temp->data=2;
        temp=temp->next;
    }
    return head;
}
