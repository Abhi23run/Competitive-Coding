/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void path(TreeNode* root,int sum,vector<int>&v,vector<vector<int>>&sol)
{
    if(root==NULL)
       return;
    if(root!=NULL)
        v.push_back(root->val);
    if(root->left==NULL && root->right==NULL)
    {
        if(sum==root->val)
        {
            sol.push_back(v);
        }
    }
    path(root->left,sum-root->val,v,sol);
    path(root->right,sum-root->val,v,sol);
    v.pop_back();
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>v;
        vector<vector<int>>sol;
        path(root,sum,v,sol);
        return sol;
    }
};