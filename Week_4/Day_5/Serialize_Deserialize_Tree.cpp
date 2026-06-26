#include<iostream>
#include<vector>
#include<string>
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

class Codec {
public:

    void dfs(TreeNode *root,string&s)
    {
        if(root==NULL){
            s+="N,";
            return;
        }
        s+=to_string(root->val)+",";
        dfs(root->left,s);
        dfs(root->right,s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        dfs(root,s);
        return s;
    }

    TreeNode *build(vector<string>&nodes,int &idx)
    {
        if(nodes[idx]=="N"){
            idx++;
            return NULL;
        }
        TreeNode *root=new TreeNode(stoi(nodes[idx]));
        idx++;
        root->left=build(nodes,idx);
        root->right=build(nodes,idx);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>nodes;
        string temp="";
        for(char ch:data)
        {
            if(ch==','){
                nodes.push_back(temp);
                temp="";
            }
            else
            temp+=ch;
        }
        int idx=0;

        return build(nodes,idx);
    }
};

void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec obj;
    string data=obj.serialize(root);
    cout<<"Seriallized Tree: "<<data<<endl;
    TreeNode *newroot=obj.deserialize(data);
    cout<<"Inorder Traversal After deserialization: ";
    inorder(root);
    cout<<endl;

    return 0;
}