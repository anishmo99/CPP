class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;

        if (s1 == s2)
            return true;

        int index1;
        int index2;
        int count = 0;
        bool flag = false;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i] and !flag)
            {
                index1 = i;
                flag = true;
                count++;
            }
            else if (s1[i] != s2[i])
            {
                index2 = i;
                count++;
            }
        }

        if (count != 2)
            return false;

        return s1[index1] == s2[index2] and s1[index2] == s2[index1];
    }
};