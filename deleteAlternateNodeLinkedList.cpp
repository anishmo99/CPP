#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    int data = x;
	    next = NULL;
	}
};

void deleteAlt(struct Node *head)
{
    if(!head)  return;
    Node *temp1=head;
    Node *temp2=head->next;
    while(temp1&&temp2)
    {
        temp1->next=temp2->next;
        free(temp2);
        temp1=temp1->next;
        if(temp1)
        {
            temp2=temp1->next;
        }
    }
}
