// accepted 
// BFS approach
// queue
void getVerticalOrder(Node *root, int hd, map<int, vector<int>>& map)
{
    if (root == nullptr)
        return;

    queue<pair<Node*, int>> queue;
    queue.push(make_pair(root, hd));

    while (!queue.empty())
    {
        pair<Node *, int> temp = queue.front();
        queue.pop();

        Node *node = temp.first;
        hd = temp.second;
        map[hd].push_back(node->data);

        if (node->left)
            queue.push(make_pair(node->left, hd - 1));
        if (node->right)
            queue.push(make_pair(node->right, hd + 1));
    }
}

vector<int> verticalOrder(Node *root)
{
    vector<int> sol;
    map<int, vector<int>> map;
    int hd = 0;
    getVerticalOrder(root, hd, map);

    for (auto x : map)
    {
        for (int i : x.second)
            sol.push_back(i);
    }
    return sol;
}

// stack / recursive approach 
// not accepted

// the below solution may print nodes in same vertical order as they appear in tree.
// For example, the above program prints 12 before 9
// DFS approach
void getVerticalOrder(Node *root, int hd, map<int, vector<int>>& map)
{
    if(root == nullptr)
        return;
        
    map[hd].push_back(root->data);
    
    getVerticalOrder(root->left, hd-1, map);
    
    getVerticalOrder(root->right, hd+1, map);
}

vector<int> verticalOrder(Node *root)
{
    vector<int> sol;
    map<int, vector<int>> map;
    int hd = 0;
    getVerticalOrder(root, hd, map);
    
    for(auto x : map)
    {
        for(int i : x.second)
            sol.push_back(i);
    }
    return sol;
}