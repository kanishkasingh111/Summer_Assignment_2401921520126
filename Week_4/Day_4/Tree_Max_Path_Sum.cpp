#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    int result = INT_MIN;

    int maxPath(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int leftsum = max(0, maxPath(root->left));
        int rightsum = max(0, maxPath(root->right));

        result = max(result,
                     leftsum + rightsum + root->val);

        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root)
    {
        maxPath(root);
        return result;
    }
};

int main()
{
    /*
             -10
             /  \
            9    20
                /  \
               15   7

        Maximum Path:
        15 -> 20 -> 7

        Sum = 42
    */

    TreeNode* root = new TreeNode(-10);

    root->left = new TreeNode(9);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Path Sum = "
         << obj.maxPathSum(root)
         << endl;

    return 0;
}