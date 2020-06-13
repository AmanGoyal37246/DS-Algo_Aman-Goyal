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
int maxPathSum(BinaryTreeNode* root){
        if(root==NULL)
            return 0;

        int l=maxPathSum(root->left);
        int r=maxPathSum(root->right);
        int maxPath=max(max(l,r)+root->data,root->data);
        int ans=max(maxPath,l+r+root->data);
        return ans;
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
    cout<<maxPathSum(root);
}
