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
    int result=0;
    int solve(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        int left=solve(root->left);
        int right=solve(root->right);
        int sum=left+right;
        result=max(result,sum);
        
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return result;
    }
};

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    Solution obj;
    cout<<"Diameter="<<obj.diameterOfBinaryTree(root)<<endl;

    return 0;
}