//
// Created by Anish Mookherjee on 28/05/20.
//

/* A binary tree node structure

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
 */

// This function should return tree if passed  tree
// is balanced, else false.

int height(Node *root)
{
    if(root==NULL)
        return 0;

    return 1 + max(height(root->left),height(root->right));
}

bool isBalanced(Node *root)
{
    if(root==NULL)
        return 1;

    int lh,rh;
    lh=height(root->left);
    rh=height(root->right);

    return (abs(lh-rh)<=1&&isBalanced(root->left)&&isBalanced(root->right));
}
