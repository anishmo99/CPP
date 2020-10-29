class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        if (strs.size() == 1)
            return strs[0];

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (strs[i][j] == prefix[j] and j < prefix.size() and j < strs[i].size())
            {
                j++;
            }
            prefix = prefix.substr(0, j);
        }

        return prefix;
    }
};