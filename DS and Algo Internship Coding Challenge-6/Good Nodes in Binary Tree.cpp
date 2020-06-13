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
void helper(BinaryTreeNode* root,int large,int &c)
{
    if(root==NULL)
        return;

    if(root->data>=large)
    {
        large=root->data;
        c++;
    }
    helper(root->left,large,c);
    helper(root->right,large,c);
}
int goodNodes(BinaryTreeNode* root)
{
    int ans=0;
    helper(root,INT_MIN,ans);
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
    cout<<goodNodes(root);
}
