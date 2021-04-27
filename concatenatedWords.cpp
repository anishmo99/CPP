// TRIE

class TrieNode
{
public:
    TrieNode *link[26];
    bool is_end;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            link[i] = NULL;
        }
        is_end = false;
    }
    static TrieNode *insert(TrieNode *root, string str)
    {
        if (root == NULL)
        {
            root = new TrieNode;
        }
        TrieNode *temp = root;
        int i = 0;
        while (i < str.size())
        {
            if (temp->link[str[i] - 'a'] == NULL)
            {
                temp->link[str[i] - 'a'] = new TrieNode;
            }
            temp = temp->link[str[i] - 'a'];
            i++;
        }
        temp->is_end = true;
        return root;
    }
    static void mark(TrieNode *root, string str, vector<bool> &dp, int l, int r)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->is_end)
        {
            dp[l] = true;
        }
        if (l == r)
        {
            return;
        }
        if (root->link[str[l] - 'a'] != NULL)
        {
            mark(root->link[str[l] - 'a'], str, dp, l + 1, r);
        }
    }
};

class Solution
{
public:
    // sort on the basis of string length
    static bool sorter(string a, string b)
    {
        return a.size() < b.size();
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> ans;
        sort(words.begin(), words.end(), sorter);
        TrieNode *root = NULL;
        vector<bool> singles(26, false); // this is for the hack

        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == "")
            {
                continue;
            }
            if (words[i].size() == 1)
            {
                // this can never be the answer, but is a good building block
                singles[words[i][0] - 'a'] = true;
                root = TrieNode::insert(root, words[i]);
                continue;
            }
            // check if the current string can be made using our single building blocks
            bool check = true;
            for (int j = 0; j < words[i].size(); j++)
            {
                if (!singles[words[i][j] - 'a'])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                ans.push_back(words[i]);
                continue;
            }

            // our vanilla trie with dp solution
            vector<bool> dp(words[i].size() + 1, false);
            dp[0] = true;
            TrieNode::mark(root, words[i], dp, 0, words[i].size());
            for (int j = 1; j < words[i].size(); j++)
            {
                if (dp[j])
                {
                    TrieNode::mark(root, words[i], dp, j, words[i].size());
                }
            }
            if (dp[words[i].size()])
            {
                ans.push_back(words[i]);
            }
            else
            {
                root = TrieNode::insert(root, words[i]);
            }
        }
        return ans;
    }
};

// unordered_sets

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        for (auto w : words)
        {
            int n = w.size();
            vector<int> dp(n + 1);
            dp[0] = 1;
            for (int i = 0; i < n; i++)
            {
                if (dp[i] == 0)
                    continue;
                for (int j = i + 1; j <= n; j++)
                {
                    if (j - i < n && s.count(w.substr(i, j - i)))
                        dp[j] = 1;
                }
                if (dp[n])
                {
                    res.push_back(w);
                    break;
                }
            }
        }
        return res;
    }
};