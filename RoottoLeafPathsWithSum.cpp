//correct solution problem in backend
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void func(TreeNode *A, int B, vector<vector<int> > &result,vector<int> &vec)
{
    if(A==NULL) return;
    vec.push_back(A->val);
    B -= A->val;
    if(A->left==NULL and A->right==NULL)
    {
        if(B==0)
            result.push_back(vec);
        vec.pop_back();
        return;
    }
    func(A->left,B,result,vec);
    func(A->right,B,result,vec);
    vec.pop_back();
    return;
    
    
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > result;
    vector<int> vec;
    func(A,B,result,vec);
    return result;
}

