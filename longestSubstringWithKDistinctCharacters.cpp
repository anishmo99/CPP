#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringWithKDistinctCharacters(string str, int k)
{
    int kcount = 0;
    int i = 0, j = 0;
    int max_count = 0;
    unordered_map<char, int> ump;
    while (j < str.size())
    {
        if (kcount <= k)
        {
            if (ump.find(str[j]) == ump.end())
            {
                kcount++;
            }
            ump[str[j]]++;
            if (kcount == k)
            {
                max_count = max(max_count, j - i + 1);
            }
            j++;
        }
        else
        {
            ump[str[i]]--;
            if (ump[str[i]] == 0)
            {
                ump.erase(str[i]);
                kcount--;
            }
            i++;
        }
    }
    if (max_count == 0)
        return -1;
    return max_count;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        string str;
        int k;
        cin >> str >> k;
        cout << longestSubstringWithKDistinctCharacters(str, k) << endl;
    }
}

// OR directly using hash_map size

int longestSubstringWithKDistinctCharacters(string str, int k)
{
    int i = 0, j = 0;
    int max_count = 0;
    unordered_map<char, int> ump;
    while (j < str.size())
    {
        if (ump.size() <= k)
        {
            ump[str[j]]++;
            if (ump.size() == k)
            {
                max_count = max(max_count, j - i + 1);
            }
            j++;
        }
        else
        {
            ump[str[i]]--;
            if (ump[str[i]] == 0)
                ump.erase(str[i]);
            i++;
        }
    }
    if (max_count == 0)
        return -1;
    return max_count;
}