class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> ans;
	    vector<int> visited(V, false);
	    
	    stack<int> stk;
	    stk.push(0);
	    
	    while(!stk.empty()){
	        int node = stk.top();
	        stk.pop();
	        
	        visited[node] = true;
	        
	        for(int i = 0; i < adj[node].size(); i++){
	            if(!visited[adj[node][i]]){
	                stk.push(adj[node][i]);
	                visited[adj[node][i]] = true;
	            }
	        }
	    }
	    
	    return ans;
	}
};

// recursive

class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	vector<int> ans;
	
	void dfs(int V, vector<int> adj[], vector<bool>& visited){
	    if(!visited[V]){
	        visited[V] = true;
	        ans.push_back(V);
	        
	        for(int i = 0; i < adj[V].size(); i++){
	            dfs(adj[V][i], adj, visited);
	        }
	    }
	}
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<bool> visited(V, false);
	    
	    dfs(0, adj, visited);
	    
	    return ans;
	}
};