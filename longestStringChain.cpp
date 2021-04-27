class Solution {
public:
    static bool comp(string& a, string& b){
        return a.size() < b.size();
    }

    int lcs(string& X, string& Y)  
    {  
        int m = X.length();
        int n = Y.length();  
        int L[m + 1][n + 1];  
        int i, j;  
        for (i = 0; i <= m; i++)  
        {  
            for (j = 0; j <= n; j++)  
            {  
            if (i == 0 || j == 0)  
                L[i][j] = 0;  

            else if (X[i - 1] == Y[j - 1])  
                L[i][j] = L[i - 1][j - 1] + 1;  

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
            }  
        }  
        return L[m][n];  
    }  

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        
        vector<int> rem(words.size(), 1);
        
        for(int i = 1; i < words.size(); i++){
            for(int j = 0; j < i; j++){

                if(words[i].size() - words[j].size() == 1 and words[j].size() == lcs(words[i], words[j]) and rem[i] < rem[j] + 1)
                    rem[i] = rem[j] + 1;
            }
        }
        
        return *max_element(rem.begin(), rem.end());
    }
};