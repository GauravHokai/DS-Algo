/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void leftbound(TreeNode *root, vector<int> &ans)
{
    if(!root) return;
    if(root->left)
    {
        ans.push_back(root->val);
        leftbound(root->left,ans);
    }
    else if(root->right)
    {
        ans.push_back(root->val);
        leftbound(root->right,ans);
    }
}
void leaves(TreeNode *root, vector<int> &ans)
{
    if(!root) return;
    leaves(root->left,ans);
    leaves(root->right,ans);
    if(!root->left and !root->right)
    {
        ans.push_back(root->val);
        return;
    }
}
void rightbound(TreeNode *root, vector<int> &ans)
{
    if(!root) return;
    if(root->right)
    {
        rightbound(root->right,ans);
        ans.push_back(root->val);
    }
    else if(root->left)
    {
        rightbound(root->left,ans);
        ans.push_back(root->val);
    }
    
    
}
vector<int> Solution::solve(TreeNode* A) {
    if(!A) return {};
    vector<int> ans;
    ans.push_back(A->val);
    leftbound(A->left,ans);
    leaves(A,ans);
    rightbound(A->right,ans);
    return ans;
    
}
