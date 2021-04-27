/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void populateLowerLevel(Node *root){
        if(!root)
            return;
        
        while(root){
            root -> left -> next = root -> right;
            root -> right -> next = root -> next ? root -> next -> left : nullptr;
            root = root -> next;
        }
    }
    
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        
        Node *current = root;
        while(current -> left){
            populateLowerLevel(current);
            current = current -> left;
        }
        return root;
    }
};