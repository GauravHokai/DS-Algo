/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> result;
void func(TreeNode *A, int local_depth)
{
    if(A==NULL) return;
    if(result.size()<local_depth)
    {
        result.push_back(A->val);
    }
    func(A->right,local_depth+1);
    func(A->left,local_depth+1);
    
}

vector<int> Solution::solve(TreeNode* A) {
    result.clear();
    func(A,1);
    return result;
}
