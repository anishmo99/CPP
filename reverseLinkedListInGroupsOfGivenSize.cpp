#include <iostream>
#include <stack>

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

struct node *reverse (struct node *head, int k)
{ 
    stack<int> s;
    node *temp=head;
    while(temp!=NULL)
    {
        if(s.size()==k)
        {
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        s.push(temp->data);
        temp=temp->next;
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}