void firstRecurringCharacter(string s)
{
    set<char> hash;
    bool flag = false;
    int i;
    for (i = 0; i < s.length(); i++)
    {
        if (hash.find(s.at(i)) == hash.end())
        {
            hash.insert(s.at(i));
        }
        else
        {
            flag = true;
            cout << s.at(i);
            return;
        }
    }
    if (!flag)
        cout << -1;
}