/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isValidBST(TreeNode* A) {
    if(A==NULL) return 1;
    stack<TreeNode*> s;
    TreeNode *node = NULL;
    while(A!=NULL || !s.empty())
    {
        while(A!=NULL)
        {
            s.push(A);
            A = A->left;
        }
        A = s.top();
        s.pop();
        if(node!=NULL and node->val >= A->val) return 0;
        node = A;
        A = A->right;
        
    }
    return 1;
}
