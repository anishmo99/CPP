// BFS

vector <int> bottomView(Node *root)
{
   if(!root)
    return vector<int> ();
    
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        
        Node* node = temp.first;
        
        int hd = temp.second;
        mp[hd] = node -> data;
        
        if(node -> left)
            q.push({node -> left, hd - 1});
            
        if(node -> right)
            q.push({node -> right, hd + 1});
    }
    
    vector<int> ans;
    for(auto x : mp)
        ans.push_back(x.second);
        
    return ans;
}

// DFS segmentation fault
map<int, pair<int, int>> mp;

void solve(Node *root, int curlevel, int hd){
    if(!root)
        return;
        
    if(mp.find(hd) == mp.end()){
        mp[hd] = {root -> data, curlevel};
    }
    
    else{
        pair<int, int> p = mp[hd];
        if(p.second <= curlevel){
            mp[hd].first = root -> data;
            mp[hd].second = curlevel;
        }
    }
    
    solve(root -> left, curlevel + 1, hd - 1);
    solve(root -> right, curlevel + 1, hd + 1);
}

vector <int> bottomView(Node *root)
{
    if(!root)
        return vector<int> ();
        
   solve(root, 0, 0);
   
   vector<int> ans;
   
   for(auto x : mp){
       ans.push_back(x.second.first);
   }
   
   return ans;
}