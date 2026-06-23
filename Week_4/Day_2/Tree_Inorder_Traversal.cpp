#include<iostream>
#include<algorithm>
#include<vector>
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

    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
};

int main()
{
    TreeNode *root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);

    Solution obj;
    vector<int>ans=obj.inorderTraversal(root);
    cout<<"Inorder Traversal: ";
    for(int x:ans)
    cout<<x<<" ";
    cout<<endl;

    return 0;
}