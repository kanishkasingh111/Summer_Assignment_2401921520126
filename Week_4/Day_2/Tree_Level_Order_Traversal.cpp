#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == NULL)
            return {};

        queue<TreeNode*>q;
        q.push(root);

        vector<vector<int>>ans;
        while(!q.empty())
        {
            int lvlsize=q.size();
            vector<int>temp;
            while(lvlsize--)
            {
                TreeNode* t=q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left!=NULL)  
                q.push(t->left);
                if(t->right!=NULL)  
                q.push(t->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    Solution obj;
    vector<vector<int>>ans=obj.levelOrder(root);

    for(auto level:ans)
    {
        for(int x:level)
        cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}