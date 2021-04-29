// accepted leetcode
// MCM dp

class Solution {
public:
    vector<string> dict;
    vector<vector<int>> dp;
    
    bool solve(string& s, int i, int j){
        if(i > j)
            return dp[i][j] = false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        for(string& x : dict)
            if(s.substr(i, j - i + 1) == x)
                return dp[i][j] = true;
        
        for(int k = i; k <= j - 1; k++){
            if(solve(s, i, k) and solve(s, k + 1, j))
                return dp[i][j] = true;
        }
        
        return dp[i][j] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dict = wordDict;
        int n = s.size();
        dp.clear();
        dp.resize(n + 1, vector<int> (n + 1, -1));
        return solve(s, 0, n - 1);
    }
};

// dp
// OJ: https://leetcode.com/problems/word-break/
// Author: github.com/lzl124631x
// Time: O(S^3)
// Space: O(S + W)
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> st(begin(dict), end(dict));
        int N = s.size();
        vector<bool> dp(N + 1);
        dp[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < i && !dp[i]; ++j) {
                dp[i] = dp[j] && st.count(s.substr(j, i - j));
            }
        }
        return dp[N];
    }
};

// or

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    if (dict.find(s.substr(j, i - j)) != dict.end())
                    {
                        // cout << (s.substr(j, i - j)) << " ";
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

// gfg

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    vector<bool> dp(s.size() + 1, false);

    dp[0] = true;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j])
            {
                if (dict.find(s.substr(j, i - j)) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.size()];
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        vector<string> wordDict;
        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            wordDict.push_back(temp);
        }
        string str;
        cin >> str;
        cout << wordBreak(str, wordDict) << endl;
    }
    return 0;
}

// s -> "aaaaaaa"
// dict -> [ "aaaa", "aaa" ]

//  below two pointer method not accepted
// class Solution
// {
// public:
//     bool wordBreak(string s, vector<string> &dict)
//     {
//         int i = 0, j = 0;
//         string temp;
//         while (j < s.size())
//         {
//             if (i == j)
//                 temp = s[j];
//             else
//                 temp += s[j];
//             if (find(dict.begin(), dict.end(), temp) != dict.end())
//             {
//                 j++;
//                 i = j;
//                 // cout << temp << " ";
//                 temp = "";
//             }
//             else
//                 j++;
//         }
//         return i == s.size();
//     }
// };