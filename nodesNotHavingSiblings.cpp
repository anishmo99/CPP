//
// Created by Anish Mookherjee on 27/05/20.
//


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/* Prints the nodes having no siblings.  */
vector<int> v;
void pushVector(Node* root)
{
    if(root==NULL)
        return;
    else if(!root->left&&root->right)
        v.push_back(root->right->data);
    else if(!root->right&&root->left)
        v.push_back(root->left->data);
    if(root->left)
        pushVector(root->left);
    if(root->right)
        pushVector(root->right);
}
void printSibling(Node* node)
{
    pushVector(node);

    if(v.size()==0)
    {
        cout<<-1;
    }
    else
    {
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
    }
    v.clear();

}

// also accepted using set

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/* Prints the nodes having no siblings.  */
set<int> s;
void insertSet(Node* root)
{
    if(root==NULL)
        return;
    else if(!root->left&&root->right)
        s.insert(root->right->data);
    else if(!root->right&&root->left)
        s.insert(root->left->data);
    if(root->left)
        insertSet(root->left);
    if(root->right)
        insertSet(root->right);
}
void printSibling(Node* node)
{
    insertSet(node);

    if(s.size()==0)
    {
        cout<<-1;
    }
    else
    {
        for(auto i:s)
            cout<<i<<" ";
    }
    s.clear();

}