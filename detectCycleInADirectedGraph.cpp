class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool detect(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& inCallStk){
	    if(visited[node])
	        return true;
	        
	    visited[node] = true;
	    inCallStk[node] = true;
	    
	    for(int x : adj[node]){
	        if(!visited[x] and detect(x, adj, visited, inCallStk))
	            return true;
	        else if(inCallStk[x])
	            return true;
	    }
	    inCallStk[node] = false;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<bool> visited(V, false);
	   	vector<bool> inCallStk(V, false);
	   	
	   	for(int i = 0; i < V; i++){
	   	    if(!visited[i] and detect(i, adj, visited, inCallStk))
	   	        return true;
	   	}
	   	
	   	return false;
	}
};