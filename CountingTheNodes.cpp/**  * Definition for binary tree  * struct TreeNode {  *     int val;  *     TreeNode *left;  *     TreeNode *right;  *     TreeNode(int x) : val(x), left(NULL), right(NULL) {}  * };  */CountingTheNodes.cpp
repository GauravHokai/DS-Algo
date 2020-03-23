/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solveit(TreeNode *A, int &cnt, int mx)
{
    if(A==NULL) return;
    if(A->val>mx)
    {
        cnt++;
    }
    solveit(A->left,cnt,max(mx,A->val));
    solveit(A->right,cnt,max(mx,A->val));
    
}
int Solution::solve(TreeNode* A) {
    if(A==NULL) return 0;
    int cnt = 0;
    int mx = INT_MIN;
    solveit(A,cnt,mx);
    return cnt;
}
