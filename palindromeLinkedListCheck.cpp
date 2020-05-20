#include <iostream>
#include <stack>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

bool isPalindrome(Node *head)
{
    Node *temp=head;
    stack <int> s;
    while(temp!=NULL)
    {
        s.push(temp->data);
        temp=temp->next;
    }
    while(head!=NULL)
    {
        int i=s.top();
        s.pop();
        if(i!=head->data)
            return false;
        head=head->next;
    }
    return true;
}