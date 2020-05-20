#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *insertAtBegining(Node *head, int newData) {
   Node *temp=(struct Node*)malloc(sizeof(struct Node));
   temp->data=newData;
   temp->next=head;
   head=temp;
   return head;
}

Node *insertAtEnd(Node *head, int newData)  {
   Node *tail=(struct Node*)malloc(sizeof(struct Node));
   tail->data=newData;
   if(head==NULL)
   {
       head=tail;
   }
   else
   {
       Node *temp=head;
       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
       temp->next=tail;
   }
   return head;
}
