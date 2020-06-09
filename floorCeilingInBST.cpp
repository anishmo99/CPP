#include <iostream>
#include <iomanip>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node {
    int data;
    Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

// Recursive function to insert a key into BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr)
        return newNode(key);

    // if given key is less than the root node, recur for left subtree
    if (key < root->data)
        root->left = insert(root->left, key);

    // if given key is more than the root node, recur for right subtree
    else
        root->right = insert(root->right, key);

    return root;
}

// Recursive function to find floor and ceil of a given key in a BST
// Note that floor and ceil is passed by reference to the function
void findFloorCeil(Node* root, int &floor, int &ceil, int key)
{
    // base case
    if (root == nullptr)
        return;

    // if node with key's value is found, both floor and ceil is equal
    // to the current node
    if (root->data == key)
    {
        floor = root->data;
        ceil = root->data;
        return;
    }

    // if given key is less than the root node, recur for left subtree
    else if (key < root->data)
    {
        // update ceil to current node before recursing in left subtree
        ceil = root->data;
        findFloorCeil(root->left, floor, ceil, key);
    }

    // if given key is more than the root node, recur for right subtree
    else
    {
        // update floor to current node before recursing in right subtree
        floor = root->data;
        findFloorCeil(root->right, floor, ceil, key);
    }
}

int main()
{
    /* Construct below tree
               8
             /   \
            /     \
           4       10
          / \     /  \
         /   \   /    \
        2     6 9      12
    */

    int keys[] = { 2, 4, 6, 8, 9, 10, 12 };

    Node* root = nullptr;
    for (int key : keys)
        root = insert(root, key);

    // find Ceil and Floor for each key
    for (int i = 0; i < 15; i++)
    {
        int floor=-1,ceil=-1;
        findFloorCeil(root, floor, ceil, i);

        cout << setw(2) << i << " --> ";
        cout << setw(4) << (floor<=-1?-1:floor);
        cout << setw(4) << (ceil<=-1?-1:ceil) << endl;
    }

    return 0;
}

/*
 anishmookherjee@Anishs-MacBook-Air dailyinterviewpro % ./a.out
  0 -->   -1   2
  1 -->   -1   2
  2 -->    2   2
  3 -->    2   4
  4 -->    4   4
  5 -->    4   6
  6 -->    6   6
  7 -->    6   8
  8 -->    8   8
  9 -->    9   9
 10 -->   10  10
 11 -->   10  12
 12 -->   12  12
 13 -->   12  -1
 14 -->   12  -1
 */

