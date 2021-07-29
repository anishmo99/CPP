vector<string> maps = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string &digits, int i, string comb, vector<string> &ans){
        if(i == digits.size()){
            ans.push_back(comb);
            return;
        }
        
        for(char c : maps[digits[i] - '0']){
            comb.push_back(c);
            helper(digits, i + 1, comb, ans);
            comb.pop_back();
        }
    }
    vector<string> Solution::letterCombinations(string digits) {        
        vector<string> ans;
        if(digits.empty())
            return ans;
        
        string comb;

        helper(digits, 0, comb, ans);
        
        return ans;
    }