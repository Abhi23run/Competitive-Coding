/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool Bal(TreeNode* root,int *height)
{
    int lh=0,rh=0;
    int l=0,r=0;
    if(root==NULL)
    {
        *height=0;
        return 1;
    }
    l=Bal(root->left,&lh);
    r=Bal(root->right,&rh);
    *height=(lh>rh?lh:rh)+1;
    if(abs(lh-rh)>=2)
        return 0;
    else return(l && r);
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height=0;
        return Bal(root,&height);
    }
};