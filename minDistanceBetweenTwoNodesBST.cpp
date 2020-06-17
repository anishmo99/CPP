                                           
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
                    
Node* LCA(Node* root ,int n1 ,int n2 )
{
    if(!root) return NULL;
    Node *lnode=NULL,*rnode=NULL;
    if(root->data==n1 || root->data==n2)    return root;
    lnode=LCA(root->left,n1,n2);
    rnode=LCA(root->right,n1,n2);
    if(lnode && rnode)  return root;
    return (lnode)?lnode:rnode;
}
int findLevel(Node *root,int data,int level)
{
    if(!root)   return -1;
    if(root->data==data)    return level;
    int l=findLevel(root->left,data,level+1);
    int r=findLevel(root->right,data,level+1);
    return max(l,r);
}
int findDist(Node* root, int a, int b)
{
    Node *lca=LCA(root,a,b);
    int l=findLevel(lca,a,0);
    int r=findLevel(lca,b,0);
    return l+r;
}