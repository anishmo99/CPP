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

struct Node* a;
struct Node* b;

/*
These are global variables to store heads of split lists
struct Node* a; //store head of first list
struct Node* b; //store head of second list
*/

void alternatingSplitList(struct Node* head) 
{
    if(!head)  return;
    a=head;
    b=head->next;
    struct Node *atemp=head,*btemp=head->next;
    struct Node *temp;
    while(atemp&&btemp)
    {
        atemp->next=btemp->next;
        atemp=atemp->next;
        btemp->next=NULL;
        temp=btemp;
        if(atemp)
        {
            btemp=atemp->next;
            temp->next=btemp;
        }
    }