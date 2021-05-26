class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool detect(int node, vector<int> adj[], vector<bool>& visited, int parent){
        if(visited[node])
            return true;
            
        visited[node] = true;
        
        for(int x : adj[node]){
            if(x != parent){
                if(detect(x, adj, visited, node))
                    return true;
            }
        }
        
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool> visited(V, false);
	    
	    for(int i = 0; i < V; i++){
	        if(!visited[i] and detect(i, adj, visited, -1))
	            return true;
	    }
	    
	    return false;
	}
};