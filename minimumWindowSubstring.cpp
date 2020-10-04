Question :
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example : 
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Note :
If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

c++ Solution :
class Solution {
bool isEqual(int a[],int b[]) {
    for(int i = 0; i < 60; i++) {
        if(a[i] == 0) continue;
        if(a[i] > b[i]) return false;
    }
    return true;
}
public:
    string minWindow(string s, string t) {  
        int ct[60];
    
        memset(ct,0,sizeof(ct));
        for(auto i : t) {
            ct[i - 'A']++;
        }
        int n = s.size();
        int l = 0;
        int c[60];
        int res = INT_MAX;
        int st = -1;
        memset(c,0,sizeof(c));
        for(int r = 0; r < n; r++) {
            c[s[r] - 'A']++;
            if(isEqual(ct,c)) {
                while(isEqual(ct,c)) {
                    c[s[l] - 'A']--;
                    l++;
                    if(l == n) break;
                }
                if(r - l + 2 < res) {
                    res = r - l + 2;
                    st = l - 1;
                }
            }
            // cout << st <<" " << res << " " << l <<  " "  << r << endl;
        }
        
        if(st == -1) return "";
        return s.substr(st,res);
    }
};
