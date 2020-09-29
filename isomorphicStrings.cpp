class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ump1, ump2;
        for(int i = 0; i < s.length(); i++){
            if(ump1.find(s[i]) != ump1.end() and ump1[s[i]] != t[i])
                return false;
            ump1[s[i]] = t[i];
        }
        
        for(int i = 0; i < t.length(); i++){
            if(ump2.find(t[i]) != ump2.end() and ump2[t[i]] != s[i])
                return false;
            ump2[t[i]] = s[i];
        }
        
        return true;
    }
};