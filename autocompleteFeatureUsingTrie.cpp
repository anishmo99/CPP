#include <iostream>
using namespace std;

#define charToIndex(c) ((int)c - (int)'a') 

struct TrieNode{
    struct TrieNode *children[26];
    bool isWordEnd;
};

struct TrieNode *getNode(){
    struct TrieNode *newNode = new TrieNode;

    newNode -> isWordEnd = false;

    for(int i = 0; i < 26; i++){
        newNode -> children[i] = nullptr;
    }

    return newNode;
}

void insert(struct TrieNode *root, string key){
    struct TrieNode *ptr = root;

    for(int i = 0; i < key.length(); i++){
        int index = charToIndex(key[i]);
        
        if(!ptr -> children[index]){
            ptr -> children[index] = getNode();
        }

        ptr = ptr -> children[index];
    }

    ptr -> isWordEnd = true;
}

bool search(struct TrieNode *root, string key){
    struct TrieNode *ptr = root;

    for(int i = 0; i < key.length(); i++){
        int index = charToIndex(key[i]);

        if(!ptr -> children[index])
            return false;

        ptr = ptr -> children[index];
    }

    return (ptr and ptr -> isWordEnd);
}

bool isLastNode(struct TrieNode *root){
    for(int i = 0; i < 26; i++){
        if(root -> children[i])
            return false;
    }

    return true;
}

void suggestionsRec(struct TrieNode *root, string prefix){
    if(root -> isWordEnd){
        cout << prefix << endl;
    }

    if(isLastNode(root)){
        return;
    }

    for(int i = 0; i < 26; i++){
        if(root -> children[i]){
            prefix.push_back(char(97 + i));

            suggestionsRec(root -> children[i], prefix);

            prefix.pop_back();
        }
    }
}

int printAutoSuggestions(struct TrieNode *root, string query){
    struct TrieNode* ptr = root;

    for(int i = 0; i < query.length(); i++){
        int index = charToIndex(query[i]);

        if(!ptr -> children[index])
            return 0;

        ptr = ptr -> children[index];
    }

    bool isWord = (ptr -> isWordEnd == true);

    bool isLast = isLastNode(ptr);

    if(isWord and isLast){
        cout << query << endl;
        return -1;
    }

    if(!isLast){
        string prefix = query;
        suggestionsRec(ptr, query);
        return 1;
    }
}

int main()
{
    struct TrieNode *root = getNode();
    insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell");
    insert(root, "cat");
    insert(root, "a");
    insert(root, "hel");
    insert(root, "help");
    insert(root, "helps");
    insert(root, "helping");
    int comp = printAutoSuggestions(root, "hel");

    if (comp == -1)
        cout << "No other strings found with this prefix\n";

    else if (comp == 0)
        cout << "No string found with this prefix\n";

    return 0;
}