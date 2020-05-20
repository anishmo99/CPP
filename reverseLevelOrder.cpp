#include <iostream>
#include <stack>
#include <queue>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
}; 


void reversePrint(Node *root)
{
    stack<int> s;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node *current=q.front();
        s.push(current->data);
        
        if(current->right!=NULL) q.push(current->right);
        if(current->left!=NULL) q.push(current->left);
        
        q.pop();
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}