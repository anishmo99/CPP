#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    string s;
    cin >> s;
    set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    vector<char> v;

    for (char c : s)
    {
        if (set.find(c) != set.end())
        {
            v.push_back(c);
        }
    }
    // v = [u, i, i]
    int j = v.size() - 1;
    // [t r u m p i s s h i t]
    for (int i = 0; i < s.size(); i++)
    {
        if (set.find(s[i]) != set.end())
        {
            s[i] = v[j];
            j--;
        }
    }
    cout << s;
    return 0;
}