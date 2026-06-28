#include<iostream>
#include<vector>
#include<unordered_map>
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
    unordered_map<int, int> in;
    int idx=0;
    TreeNode* solve(vector<int>& preorder,int low,int high)
    {
        if(low>high) return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        int pos=in[root->val];
        root->left=solve(preorder,low,pos-1);
        root->right=solve(preorder,pos+1,high);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        in[inorder[i]]=i;
        return solve(preorder,0,inorder.size()-1);
    }
};

int main()
{
    vector<int>preorder={3,9,20,15,7};
    vector<int>inorder={9,3,15,20,7};
    Solution obj;
    TreeNode *root=obj.buildTree(preorder,inorder);

    return 0;
}
