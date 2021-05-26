class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        
        int maxdegree = 0, maxlen = 0;
        
        for(auto x : mp){
            vector<int> temp = x.second;
            
            int degree = temp.size();
            
            int len = temp.back() - temp.front() + 1;
            
            if(maxdegree < degree){
                maxlen = len;
                maxdegree = degree;
            }
            
            if(maxdegree == degree){
                maxlen = min(maxlen, len);
            }
        }
        
        return maxlen;
    }
};