/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void search(TreeNode *A,int B, bool &flag)
{
    if(A==NULL) return;
    if(A->val==B) 
    {
        flag = true;
        return;
    }
    if(A->left) search(A->left,B,flag);
    if(A->right) search(A->right,B,flag);
    
}
TreeNode *lcaa(TreeNode *A,int B, int C)
{
    if(A==NULL || A->val==B || A->val==C) return A;
    TreeNode *left = lcaa(A->left,B,C);
    TreeNode *right = lcaa(A->right,B,C);
    if(left==NULL and right==NULL) return NULL;
    if(left!=NULL and right!=NULL) return A;
    return left==NULL?right:left;
    
}
int Solution::lca(TreeNode* A, int B, int C) {
    if(A==NULL) return -1;
    bool flag1 = false;
    bool flag2 = false;
    search(A,B,flag1);
    search(A,C,flag2);
    if(flag1==false || flag2==false)
    {
        return -1;
    }
    TreeNode *node;
    node = lcaa(A,B,C);
    return node->val;
}
