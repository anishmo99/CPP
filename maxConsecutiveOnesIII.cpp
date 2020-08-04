class Solution
{
public:
    int longestOnes(vector<int> &a, int k)
    {
        int i = 0, j = 0;

        while (i < a.size())
        {
            if (a[i] == 0)
                k--;
            if (k < 0)
            {
                if (a[j] == 0)
                    k++;
                j++;
            }
            i++;
        }
        return i - j;
    }
};
