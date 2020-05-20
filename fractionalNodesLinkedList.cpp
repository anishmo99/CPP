#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int fractional_node(struct Node *head, int k)
{
    struct Node *temp=head;
    int len=0;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    len=ceil((double)len/(double)k);
    double j=1;
    temp=head;
    while(j<len)
    {
        temp=temp->next;
        j++;
    }
    return temp->data;
}
