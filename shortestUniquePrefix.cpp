struct TrieNode
{
    TrieNode *child[26];
    bool unique;

    TrieNode()
    {
        unique = true;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

void makeTrie(TrieNode *root, string s)
{
    TrieNode *cur = root;

    for (char c : s)
    {
        if (cur->child[c - 'a'] == nullptr)
        {
            cur->child[c - 'a'] = new TrieNode();
        }
        else
            cur->child[c - 'a']->unique = false;

        cur = cur->child[c - 'a'];
    }
}

string findPrefix(TrieNode *root, string s)
{
    if (s.empty())
        return "";

    string temp;

    TrieNode *cur = root;

    for (char c : s)
    {
        temp.push_back(c);
        if (cur->child[c - 'a']->unique)
            return temp;
        cur = cur->child[c - 'a'];
    }

    return temp;
}

vector<string> Solution::prefix(vector<string> &A)
{
    TrieNode *root = new TrieNode();

    vector<string> sol;

    for (int i = 0; i < A.size(); i++)
    {
        makeTrie(root, A[i]);
    }

    for (int i = 0; i < A.size(); i++)
    {
        sol.push_back(findPrefix(root, A[i]));
    }

    return sol;
}
