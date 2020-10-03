class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> hash_set;
        int i = 0, j = 0;
        int count = 0;
        while (j < s.length())
        {
            if (hash_set.find(s.at(j)) == hash_set.end())
            {
                hash_set.insert(s.at(j));
                j++;
                count = max(count, j - i);
            }
            else
            {
                hash_set.erase(s.at(i));
                i++;
            }
        }
        return count;
    }
};
