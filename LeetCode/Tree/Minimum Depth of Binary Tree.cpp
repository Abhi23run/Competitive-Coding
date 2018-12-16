/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ld=0;
        int rd=0;
        if(!root->left)
            return 1+minDepth(root->right);
        if(!root->right)
            return 1+minDepth(root->left);
        if(!root->left and !root->right)
            return 1;
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};