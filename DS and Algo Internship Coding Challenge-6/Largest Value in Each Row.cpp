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
vector<int> largestValue(BinaryTreeNode *root)
{
    vector<int> output;
    if(root==NULL)
        return output;

    queue<BinaryTreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int count=0;
        int ans=INT_MIN;
        count=q.size();
        while(count--)
        {
            BinaryTreeNode* temp=q.front();
            q.pop();
            ans=max(ans,temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        output.push_back(ans);
    }
    return output;
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
    vector<int> v;
    v=largestValue(root);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
