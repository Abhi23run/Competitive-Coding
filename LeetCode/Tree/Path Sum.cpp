/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void isPath(TreeNode* root,int sum,int &x)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        {
            if(sum==root->val)
                x=1;
            return;
        }
        isPath(root->left,sum-root->val,x);
        isPath(root->right,sum-root->val,x);
}
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int x=0;
        if(root==NULL)
            return 0;
        isPath(root,sum,x);
        return x;
    }
};