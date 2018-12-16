/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isLeaf(TreeNode* root)
{
    if(root==NULL)
        return false;
    else if(!root->left && !root->right)
        return true;
    return false;
}
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==NULL)
            return 0;
        if(isLeaf(root->left))
        {
            sum+=root->left->val;
        }
        else if(!isLeaf(root->left))
            sum+=sumOfLeftLeaves(root->left);
        sum+=sumOfLeftLeaves(root->right);
        return sum;
    }
};