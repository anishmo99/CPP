#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

void deleteNode(Node *node)
{
    Node *prev;
    if(node==NULL)
        return;
    else
    {
        while(node->next!=NULL) //node->next because we need the data of the node->next
        {
            node->data=node->next->data; 
            prev=node;
            node=node->next;
        }
        prev->next=NULL;
    }
}