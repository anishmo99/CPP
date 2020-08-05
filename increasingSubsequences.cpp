// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7, 7], [4, 7, 7]]

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> subseq;
        set<vector<int>> res;
        
        dfs(nums, subseq, res, 0);
        
        return vector(res.begin(),res.end());
    }
    
    void dfs(vector<int>& nums, vector<int>& subseq, set<vector<int>>& result, int index)
    {
        if(subseq.size() >= 2)
            result.insert(subseq);
        
        for(int i = index; i < nums.size(); i++)
        {
            if(subseq.size() == 0 or nums[i] >= subseq.back())
            {
                subseq.push_back(nums[i]);
                dfs(nums, subseq, result, i+1);
                subseq.pop_back();
            }
        }
    }
};