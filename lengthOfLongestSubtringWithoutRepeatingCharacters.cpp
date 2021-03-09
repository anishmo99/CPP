class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max_length = 0;
        unordered_set<char> hash;
        int i = 0, j = 0;
        while (j < s.length())
        {
            if (hash.find(s[j]) == hash.end())
            {
                hash.insert(s[j]);
                max_length = max(max_length, j - i + 1);
                j++;
            }
            else
            {
                hash.erase(s[i]);
                i++;
            }
        }
        return max_length;
    }
};