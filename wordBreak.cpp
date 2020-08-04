// accepted

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