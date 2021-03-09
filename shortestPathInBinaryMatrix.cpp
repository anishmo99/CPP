class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int count = 0;
        
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1,1}, {1,-1}, {-1,1}, {-1, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        
        queue<pair<int, int>> q;
        
        if(grid[0][0] or grid[grid.size() - 1][grid[0].size() - 1])
            return -1;
        
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        while(!q.empty()){
            int steps = q.size();
            
            count++;
            
            for(int i = 0; i < steps; i++){
                
                auto temp = q.front();
                q.pop();
                
                int x = temp.first;
                int y = temp.second;
                
                if(x == grid.size() - 1 and y == grid[0].size() - 1)
                    return count;
                
                for(int j = 0; j < 8; j++){
                    int x1 = x + dir[j][0];
                    int y1 = y + dir[j][1];
                    
                    
                    if(x1 >= 0 and y1 >= 0 and x1 < grid.size() and y1 < grid[0].size()){
                        
                        if(!visited[x1][y1] and !grid[x1][y1]){
                            visited[x1][y1] = true;
                            q.push(make_pair(x1, y1));
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0]==1)
            return -1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        
        queue<pair<int,int>> q;
        dist[0][0] = 1;
        
        q.push({0,0});
     
        vector<vector<int>> points = {{1,0},{0,1},{1,1},{-1,0},{0,-1},{1,-1},{-1,1},{-1,-1}};
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0;i<8;i++)
            {
                int xd = x+points[i][0];
                int yd = y+points[i][1];
                
                if(xd<0 or yd<0 or xd>=n or yd>=m or grid[xd][yd]==1) // can't take these paths to reach grid[n-1][m-1]
                    continue;
                
                if(dist[xd][yd]>dist[x][y]+1)
                {
                    dist[xd][yd] = dist[x][y]+1;
                    q.push({xd,yd});
                }    
            }
        }
        
        if(dist[n-1][m-1]==INT_MAX)
            return -1;
        
        return dist[n-1][m-1];
    }
};