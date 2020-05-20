#include <iostream>
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

bool isIdentical(Node *r1, Node *r2)
{
    if(r1==NULL&&r2==NULL)
        return 1;
    else if(r1!=NULL && r2!=NULL)
        return (r1->data==r2->data &&
        isIdentical(r1->left,r2->left) &&
        isIdentical(r1->right,r2->right));
    else
        return 0;
}