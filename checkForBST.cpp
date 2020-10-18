/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

bool dfs(Node *root, Node *low, Node *high)
{
    if (!root)
        return true;

    if (low and root->data <= low->data)
        return false;

    if (high and root->data >= high->data)
        return false;

    return dfs(root->left, low, root) and dfs(root->right, root, high);
}

// return true if the given tree is a BST, else return false
bool isBST(Node *root)
{
    return dfs(root, nullptr, nullptr);
}