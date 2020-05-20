#include <iostream>
#include <queue>
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

void levelOrder(Node* node)
{
    if(node==NULL)
        return;
    else
    {
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            int nodeCount=q.size;
            while(nodeCount>0){
            Node *current=q.front();
            cout<<current->data<<" ";
            if(current->left!=NULL) 
                q.push(current->left);
            if(current->right!=NULL)
                q.push(current->right);
            q.pop();
            }
            cout<<endl;
        }
    }
}