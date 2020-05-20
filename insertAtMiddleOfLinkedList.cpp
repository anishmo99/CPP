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

Node* insertInMiddle(Node* head, int x)
{
    Node *newptr=(struct Node*)malloc(sizeof(struct Node));
    newptr->data=x;
	Node *fast=head,*slow=head;
	while(fast->next&&fast->next->next)
	{
	    fast=fast->next->next;
	    slow=slow->next;
	}
	Node *temp=slow->next;
	slow->next=newptr;
	newptr->next=temp;
	return head;
}