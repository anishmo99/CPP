//
// Created by Anish Mookherjee on 27/05/20.
//

//* A binary tree node has data, pointer to left child
//        and a pointer to right child /
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

/* Should convert tree to its mirror */
void mirror(Node* node)
{
    if(node==NULL)
        return;
    struct Node* temp;
    mirror(node->left);
    mirror(node->right);

    temp=node->left;
    node->left=node->right;
    node->right=temp;
}