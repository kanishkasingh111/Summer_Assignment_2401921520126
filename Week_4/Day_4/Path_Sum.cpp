#include<iostream>
#include<algorithm>
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

    bool result=false;
    void solve(TreeNode* root, int sum, int targetSum)
    {
        if(root==NULL)
        return;

        sum += root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
            result=true;
            return;
        }
        solve(root->left,sum,targetSum);
        solve(root->right,sum,targetSum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        solve(root,0,targetSum);
        return result;
    }
};

int main()
{
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);

    Solution obj;
    if(obj.hasPathSum(root,22))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;

    return 0;
}