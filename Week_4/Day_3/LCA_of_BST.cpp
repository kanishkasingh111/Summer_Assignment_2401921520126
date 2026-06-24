#include<iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

class Solution {
public:

    TreeNode *ans=NULL;
    void solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
        return;

        if(root==p || root==q)
        {
            ans=root;
            return;
        }
        if(root->val < p->val)
        solve(root->right,p,q);
        else if(root->val > q->val)
        solve(root->left,p,q);
        else
        {
            ans=root;
            return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < q->val)
        solve(root,p,q);
        else
        solve(root,q,p);

        return ans;
    }
};

int main()
{
    TreeNode *root=new TreeNode(6);
    root->left=new TreeNode(2);
    root->right=new TreeNode(8);

    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(4);

    root->right->left=new TreeNode(7);
    root->right->right=new TreeNode(9);

    root->left->right->left=new TreeNode(3);
    root->left->right->right=new TreeNode(5);

    TreeNode *p=root->left;
    TreeNode *q=root->right;

    Solution obj;
    TreeNode *result=obj.lowestCommonAncestor(root,p,q);

    if(result!=NULL)
    cout<<"LCA:"<<result->val<<endl;
    else
    cout<<"LCA not Found"<<endl;

    return 0;
}