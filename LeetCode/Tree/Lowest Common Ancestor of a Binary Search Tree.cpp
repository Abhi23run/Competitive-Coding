/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(root==NULL)
        return NULL;
    else if(root->val>p->val && root->val>q->val)
        return lca(root->left,p,q);
    else if(root->val<p->val && root->val<q->val)
        return lca(root->right,p,q);
    else
        return root;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        struct TreeNode* t;
        t=lca(root,p,q);
        return t;
    }
};