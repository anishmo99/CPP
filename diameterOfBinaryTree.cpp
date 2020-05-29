//
// Created by Anish Mookherjee on 28/05/20.
//


/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Computes the diameter of binary tree with given root.  */
int height(Node* root)
{
    if(root==NULL)
        return 0;

    return max(height(root->left),height(root->right))+1;
}
int diameter(Node* node) {
    if(node==NULL)
        return 0;
    int lh=height(node->left);
    int rh=height(node->right);

    return max(lh+rh+1,max(diameter(node->left),diameter(node->right)));
}
