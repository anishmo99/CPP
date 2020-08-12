struct Node
{
	int data;
	Node* left, * right;
};

bool dfs(Node *node, int& sum, int temp_sum){
    if(!node)
        return false;
    
    temp_sum+=node->data;    
    
    if(temp_sum==sum and !node->left and !node->right)
        return true;
    
    return dfs(node->left, sum, temp_sum) || dfs(node->right, sum, temp_sum);
}
bool hasPathSum(Node *node, int sum) {
    int temp_sum = 0;
    return dfs(node, sum, temp_sum);
}