class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int ans = citations.size();
        
        for(int i = 0; i < citations.size(); i++){
            if (ans <= citations[i])
                return ans;
            else
                ans--;
        }
        
        return ans;
    }
};

// 0 1 3 5 6