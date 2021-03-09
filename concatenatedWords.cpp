// TRIE

class Solution
{
public:
    static bool comp(string a, string b)
    {
        return a.size() < b.size();
    }

    struct Node
    {
        Node() : wordEnd(), next(){};
        bool wordEnd;
        Node *next[26];
    };

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> res;

        sort(words.begin(), words.end(), comp);

        Node *root = new Node();

        for (string word : words)
        {
            if (canbreak(0, word, root))
                res.push_back(word);

            addword(word, root);
        }

        return res;
    }

    bool canbreak(int index, string word, Node *root)
    {
        if (index == word.size())
            return true;

        string s;

        for (int i = index; i < word.size(); i++)
        {
            if (search(s += word[i], root) and canbreak(i + 1, word, root))
                return true;
        }

        return false;
    }

    void addword(string word, Node *root)
    {
        for (char c : word)
        {
            if (!root->next[c - 'a'])
                root->next[c - 'a'] = new Node();

            root = root->next[c - 'a'];
        }

        root->wordEnd = true;
    }

    bool search(string word, Node *root)
    {
        for (char c : word)
        {
            if (!root->next[c - 'a'])
                return false;

            root = root->next[c - 'a'];
        }

        return root->wordEnd;
    }
};

// unordered_sets TLE

class Solution
{
public:
    static bool comp(string &a, string &b)
    {
        return a.size() < b.size();
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        unordered_set<string> set;

        vector<string> ans;

        sort(words.begin(), words.end(), comp);

        for (string word : words)
        {
            if (word.empty())
                continue;

            if (canbreak(0, word, set))
                ans.push_back(word);

            set.insert(word);
        }

        return ans;
    }

    bool canbreak(int index, string &word, unordered_set<string> &set)
    {
        if (index == word.size())
            return true;

        string s;

        for (int i = index; i < word.size(); i++)
        {
            if (set.count(s += word[i]) > 0 and canbreak(i + 1, word, set))
                return true;
        }

        return false;
    }
};