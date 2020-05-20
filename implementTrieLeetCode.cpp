class Trie {
private:
    struct TrieNode
    {
        struct TrieNode *child[26];
        bool isEnd;
    };
    TrieNode* node;
public:
    /** Initialize your data structure here. */
    Trie() {
        node=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur=node;
        for(char c:word)
        {
            if(cur->child[c-'a']==NULL)
                cur->child[c-'a']=new TrieNode();
            cur=cur->child[c-'a'];
        }
        cur->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur=node;
        for(char c:word)
        {
            if(cur->child[c-'a']==NULL)
                return false;
            cur=cur->child[c-'a'];
        }
        if(cur->isEnd==true)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur=node;
        for(char c:prefix)
        {
            if(cur->child[c-'a']==NULL)
                return false;
            cur=cur->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
