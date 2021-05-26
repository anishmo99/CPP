class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<bool> visited(V, false);
	    vector<int> ans;
	    queue<int> q;
	    q.push(0);
	    visited[0] = true;
	    
	    while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(int j = 0; j < adj[temp].size(); j++){
                if(!visited[adj[temp][j]]){
                    q.push(adj[temp][j]);
                    visited[adj[temp][j]] = true;
                }
            }
	    }
	    return ans;
	}
};