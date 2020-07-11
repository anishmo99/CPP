/*  Structure of a Binary Tree 

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

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node *root)
{
    if (root == nullptr)
        return 0;
    queue<Node *> q;
    q.push(root);
    int result = 1;
    while (!q.empty())
    {
        int n = q.size();
        result = max(result, n);
        for (int i = 0; i < n; i++)
        {
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }
    return result;
}