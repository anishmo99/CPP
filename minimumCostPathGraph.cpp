class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), INT_MAX));
        dp[0][0] = grid[0][0];
        
        priority_queue<pair<int, pair<int, int>> ,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        pq.push({grid[0][0],{0, 0}});
        
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!pq.empty()){
            auto temp = pq.top();
            int x = temp.second.first;
            int y = temp.second.second;
            int dist = temp.first;
            
            pq.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                
                if(nx >= 0 and nx < grid.size() and ny >= 0 and ny < grid[0].size() and (grid[nx][ny] + dist < dp[nx][ny])){
                    dp[nx][ny] = grid[nx][ny] + dist;
                    pq.push({dp[nx][ny], {nx, ny}});
                }
            }
        }
        
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};