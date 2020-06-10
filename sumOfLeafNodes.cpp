//
// Created by Anish Mookherjee on 27/05/20.
//

struct Node
{
    int data;
    Node *left, *right;
};

// function should return the sum of all the
// leaf nodes of the binary tree

int sumLeaf(Node* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return root->data;
    return sumLeaf(root->left)+sumLeaf(root->right);
}