/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void func(TreeNode *A, vector<int> &result, int &g_depth, int local_depth)
{
    if(A==NULL) return;
    if(local_depth>g_depth)
    {
        result.push_back(A->val);
        g_depth = local_depth;
    }
    func(A->left,result,g_depth,local_depth+1);
    func(A->right,result,g_depth,local_depth+1);
}

vector<int> Solution::solve(TreeNode* A) {
    vector<int> result;
    int g_depth = INT_MIN;
    func(A,result,g_depth,0);
    return result;
}
