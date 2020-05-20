#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

void printSpiral(Node *root)
{
    if(root==NULL)
        return;
    stack<Node *> s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node *temp=s1.top();
            cout<<temp->data<<" ";
            s1.pop();
            if(temp->right)
            {
                s2.push(temp->right);
            }
            if(temp->left)
            {
                s2.push(temp->left);
            }
        }
        while(!s2.empty())
        {
            Node *temp=s2.top();
            cout<<temp->data<<" ";
            s2.pop();
            if(temp->left)
            {
                s1.push(temp->left);
            }
            if(temp->right)
            {
                s1.push(temp->right);
            }
        }
        
    }
}
