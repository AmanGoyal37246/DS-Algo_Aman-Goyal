#include<bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{
    public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
         this->data=data;
         left=NULL;
         right=NULL;
    }
};
int lca(BinaryTreeNode* root,int p,int q)
{
     if(root==NULL)
     {
         return 0;
     }
     if(root->data==p ||  root->data==q){
         return root->data;
     }
     int a=lca(root->left,p,q);
     int b=lca(root->right,p,q);
     if(a==NULL && b!=NULL)
     {
         return b;
     }
     else if(a!=NULL && b==NULL)
     {
         return a;
     }
     else if(a==NULL && b==NULL)
     {
         return NULL;
     }
     else if(a!=NULL && b!=NULL)
     {
         return root->data;
     }

}
BinaryTreeNode* takeInput()
{
    int rootData;
    cin>>rootData;
    if(rootData==-1)
        return NULL;
    BinaryTreeNode* root=new BinaryTreeNode(rootData);
    queue<BinaryTreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode* currentNode=q.front();
        q.pop();
        int leftChild,rightChild;
        cin>>leftChild;
        if(leftChild!=-1)
        {
             BinaryTreeNode* leftNode=new BinaryTreeNode(leftChild);
             currentNode->left=leftNode;
             q.push(leftNode);
        }
        cin>>rightChild;
        if(rightChild!=-1)
        {
             BinaryTreeNode* rightNode=new BinaryTreeNode(rightChild);
             currentNode->right=rightNode;
             q.push(rightNode);
        }
    }
    return root;
}
int main()
{
    BinaryTreeNode* root=takeInput();
    int a,b;
    cin>>a>>b;
    cout<<lca(root,a,b);
}
