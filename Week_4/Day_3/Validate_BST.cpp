#include<iostream>
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
    vector<int>ans;
    void solve(TreeNode* root)
    {
        if(root==NULL) return;
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }

    bool isValidBST(TreeNode* root) {
        solve(root);
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]>=ans[i+1])
                return false;
        }
        return true;
    }
};

int main()
{
    TreeNode *root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);

    Solution obj;
    if(obj.isValidBST(root))
    cout<<"Valid BST"<<endl;
    else
    cout<<"Not a BST"<<endl;

    return 0;
}