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

    bool tree(TreeNode *p,TreeNode *q)
    {
        if(p==NULL && q==NULL)
        return true;

        if(p==NULL || q==NULL)
        return false;

        if(p->val != q->val)
        return false;

        bool r1=tree(p->left,q->right);
        bool r2=tree(p->right,q->left);

        if(r1==true && r2==true)
        return true;

        return false;
    }


    bool isSymmetric(TreeNode* root) {
        return tree(root->left,root->right);
    }
};

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);

    Solution obj;
    if(obj.isSymmetric(root))
    cout<<"Symmetric Tree"<<endl;
    else
    cout<<"Not Symmetric Tree"<<endl;

    return 0;
}