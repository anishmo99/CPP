class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int all_upper = 0, all_lower = 0, first_cap = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (i == 0)
            {
                if (islower(word[i]))
                    all_lower++;
                else
                {
                    all_upper++;
                    first_cap++;
                }
            }
            else
            {
                if (islower(word[i]))
                {
                    all_lower++;
                    first_cap++;
                }
                else
                    all_upper++;
            }
        }
        return all_upper == word.size() or all_lower == word.size() or first_cap == word.size();
    }
};