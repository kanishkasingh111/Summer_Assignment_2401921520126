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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
        return true;

        if(p==NULL || q==NULL)
        return false;

        if(p->val != q->val)
        return false;

        bool r1=isSameTree(p->left,q->left);
        bool r2=isSameTree(p->right,q->right);

        if(r1==true && r2==true)
        return true;

        return false;

    }
};

int main()
{
    TreeNode *p=new TreeNode(1);
    p->left=new TreeNode(2);
    p->right=new TreeNode(3);
    
    TreeNode *q=new TreeNode(1);
    q->left=new TreeNode(2);
    q->right=new TreeNode(3);

    Solution obj;
    if(obj.isSameTree(p,q))
    cout<<"Same Tree"<<endl;
    else
    cout<<"Not Same Tree"<<endl;

    return 0;

}