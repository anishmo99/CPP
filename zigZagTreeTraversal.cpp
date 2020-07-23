// gfg

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector <int> zigZagTraversal(Node* root)
{
	vector<int>result;
	if(root == nullptr)
	    return result;
	
	stack<Node*>s1;
	stack<Node*>s2;
	s1.push(root);

	while(!s1.empty() or !s2.empty())
	{
		while(!s1.empty())
		{
			root = s1.top();
			result.push_back(root->data);
			s1.pop();
			if(root->left)
				s2.push(root->left);
			if(root->right)
				s2.push(root->right);
		}
		while(!s2.empty())
		{
			root = s2.top();
			result.push_back(root->data);
			s2.pop();
			if(root->right)
				s1.push(root->right);
			if(root->left)
				s1.push(root->left);
		}
	}

	return result;
}