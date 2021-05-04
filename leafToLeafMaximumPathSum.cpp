int ans;

int fun(Node* root)
{
    if(root==NULL)
    return 0;
    
    if(root->left==NULL and root->right==NULL)
    return root->data;
    
    int left = fun(root->left);
    int right = fun(root->right);
    
    if(root->left and root->right)
    {
        ans = max(ans,left+right+root->data);
        return max(left,right) + root->data;
    }
    
    if(root->left==NULL)
    return right + root->data;
    else
    return left + root->data;
}

int maxPathSum(Node* root)
{
    ans = INT_MIN;
    fun(root);
    
    return ans;
}