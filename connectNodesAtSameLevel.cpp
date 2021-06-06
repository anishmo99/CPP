class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       if(!root)
        return;
        
        root -> nextRight = nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        Node* temp;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* prev = temp;
                temp = q.front();
                q.pop();
                
                
                if(i > 0){
                    prev -> nextRight = temp;
                }
                
                if(temp -> left)
                    q.push(temp -> left);
                
                if(temp -> right)
                    q.push(temp -> right);
                    
                temp -> nextRight = nullptr;
            }
        }
    }    
};
