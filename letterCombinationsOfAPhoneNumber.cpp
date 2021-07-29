class Solution {
public:
    vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
    vector<string> letterCombinations(string digits) {        
        if(digits.empty())
            return ans;
        
        string comb;
        
        helper(digits, 0, comb);
        
        return ans;
        }
    
    void helper(string digits, int i, string &comb){
        if(i == digits.size()){
            ans.push_back(comb);
            return;
        }
        
        for(auto c : map[digits[i] - '2']){
            comb.push_back(c);
            helper(digits, i + 1, comb);
            comb.pop_back();
        }
    }
};