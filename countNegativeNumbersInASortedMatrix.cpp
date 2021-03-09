class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    	// O(NlogM)
        int res = 0, n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            // the first number which is greater than -1 in the reverse array grid[i]
            res += upper_bound(grid[i].rbegin(), grid[i].rend(), -1) - grid[i].rbegin();
        }
        return res;
    }
};


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int count = 0;
        
        for(vector<int> row : grid){
            count += upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin();
        }
        
        return count;
    }
};


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
 // Search Break Points: O(m + n) - traverse from upper right to lower left
        int m(grid.size()), n(grid[0].size()), r(0), c(n - 1);
        while (r < m) {
            while (c >= 0 && grid[r][c] < 0) c--;
            ans += n - c - 1;
            r++;
        }
        return ans;
    }
};