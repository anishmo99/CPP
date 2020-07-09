#include <iostream>
using namespace std;

bool checkMeta(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    int count = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            count++;
    }
    return (count == 2);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << checkMeta(s1, s2) << endl;
    }
    return 0;
}