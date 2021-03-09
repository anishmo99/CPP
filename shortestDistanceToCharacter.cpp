class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> cindex;
        vector<int> result;
        for (int i = 0; i < S.size(); i++)
            if (S[i] == C)
                cindex.push_back(i);

        for (int i = 0; i < S.size(); i++)
        {
            int mini = abs(i - cindex[0]);
            for (int j = 1; j < cindex.size(); j++)
            {
                if (mini > abs(i - cindex[j]))
                    mini = abs(i - cindex[j]);
            }
            result.push_back(mini);
        }
        return result;
    }
};