// dp

class Solution {    
public:
    string shortestCommonSupersequence(string a, string b) {
        
        int m = a.size();
        int n = b.size();
        
        vector<vector<int>> t(m + 1, vector<int> (n + 1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i == 0 or j == 0)
                    t[i][j] = 0;
                
                if(a[i - 1] == b[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
        
        string ans;
        
        
        while(m > 0 and n > 0){
            if(a[m - 1] == b[n - 1]){
                ans += a[m - 1];
                m--;
                n--;
            }
            
            else if(t[m - 1][n] > t[m][n - 1]){
                ans += a[m - 1];
                m--;
            }
            
            else{
                ans += b[n - 1];
                n--;
            }
        }
        
        while(m > 0){
            ans += a[m - 1];
            m--;
        }
        
        while(n > 0){
            ans += b[n - 1];
            n--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};