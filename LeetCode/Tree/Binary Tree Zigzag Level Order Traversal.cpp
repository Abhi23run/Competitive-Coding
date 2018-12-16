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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*>s;
        int flag=1;
        s.push(root);
        while(!s.empty())
        {
            vector<int>v;
            stack<TreeNode*>temp;
            while(!s.empty())
            {
                TreeNode* t=s.top();
                s.pop();
                v.push_back(t->val);
                if(flag==1)
                {
                    if(t->left)
                        temp.push(t->left);
                    if(t->right)
                        temp.push(t->right);
                }
                else if(flag==-1)
                {
                    if(t->right)
                        temp.push(t->right);
                    if(t->left)
                        temp.push(t->left);
                }
            }
            ans.push_back(v);
            s=temp;
            flag*=-1;
        }
        return ans;  
    }
};