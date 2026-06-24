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

    void solve(TreeNode* root, int val)
    {
        if(root==NULL)
        return;

        if(root->val==val)
        {
            ans=root;
            return;
        }
        else if(root->val<val)
        solve(root->right,val);
        else
        solve(root->left,val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        solve(root,val);
        return ans;
    }
};

int main()
{
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);

    Solution obj;
    TreeNode *result=obj.searchBST(root,2);

    if(result)
    cout<<"Found Node: "<<result->val<<endl;
    else
    cout<<"Node not Found"<<endl;

    return 0;
}