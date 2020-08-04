// accepted leetcode

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