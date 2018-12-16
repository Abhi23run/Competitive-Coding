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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>sol;
        if(root==NULL)
            return sol;
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        v.push_back(root->val);
        sol.push_back(v);
        while(!q.empty())
        {
            queue<TreeNode*>temp;
            vector<int>v1;
            while(!q.empty())
            {
                TreeNode* cur=q.front();
                q.pop();
                v.pop_back();
                if(cur->left)
                {
                    temp.push(cur->left);
                    v1.push_back(cur->left->val);
                }
                if(cur->right)
                {
                    temp.push(cur->right);
                    v1.push_back(cur->right->val);
                }
            }
            q=temp;
            v=v1;
            if(v.size()>0)
                sol.push_back(v);
        }
        return sol;
    }
};