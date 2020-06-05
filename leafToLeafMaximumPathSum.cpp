//Node is as follows
struct Node{
    int data;
    Node *left, *right;
};

int dfs(Node *root,int &ans)
{
    if(!root)
        return INT_MIN;
    
    if(!root->left&&!root->right)
        return root->data;
        
    int left_data=dfs(root->left,ans);
    int right_data=dfs(root->right,ans);
    
    if(root->left&&root->right)
        ans=max(left_data+right_data+root->data,ans);
    
    return max(left_data,right_data)+root->data;
}

int maxPathSum(Node *root) {
    int ans=INT_MIN;
    dfs(root,ans);
    return ans;
}
