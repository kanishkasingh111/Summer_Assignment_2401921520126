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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        return root;

        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

void inorder(TreeNode *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main()
{
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    Solution obj;
    cout<<"Before:";
    inorder(root);
    cout<<endl;
    obj.invertTree(root);
    cout<<"After:";
    inorder(root);
    cout<<endl;

    return 0;
}