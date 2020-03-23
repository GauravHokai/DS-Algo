/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void func(vector<int> &res, TreeNode *root, int C, unordered_set<TreeNode*> &uset,unordered_map<TreeNode*, TreeNode*> &umap)
{
    if(root==NULL) return;
    if(uset.find(root)!=uset.end())
    {
        return;
    }
    uset.insert(root);
    if(C==0)
    {
        res.push_back(root->val);
        return;
    }
    if(root->left)
    {
        func(res,root->left,C-1,uset,umap);
        
    }
    if(root->right)
    {
        func(res,root->right,C-1,uset,umap);
    }
    TreeNode *node = umap[root];
    if(node)
    {
        func(res,node,C-1,uset,umap);
    }
    
}
void findparent(TreeNode *A,unordered_map<TreeNode*, TreeNode*> &umap)
{
    if(A==NULL) return;
    if(A->left)
    {
        umap[A->left] = A;
        findparent(A->left,umap);
    }
    if(A->right)
    {
        umap[A->right] = A;
        findparent(A->right,umap);
    }
}
vector<int> Solution::solve(TreeNode* A, int B, int C) {
    if(A==NULL) return {};
    unordered_map<TreeNode*, TreeNode*> umap;
    unordered_set<TreeNode*> uset;
    findparent(A,umap);
    
    TreeNode *node = NULL;
    stack<TreeNode*> s;
    while(A!=NULL || !s.empty())
    {
        while(A!=NULL)
        {
            s.push(A);
            A = A->left;
        }
        A = s.top();
        s.pop();
        if(A->val==B)
        {
            node = A;
            break;
        }
        A = A->right;
    }
    
    vector<int> res;
    func(res,node,C,uset,umap);
    return res;
}
