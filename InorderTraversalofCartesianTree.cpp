/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findMax(vector<int> &A, int start, int end)
{
    int max = A[start];
    int index = start;
    for(int i = start; i <= end; i++){
        if(max < A[i]){
            max = A[i];
            index = i;
        }
    }
    return index;
} 
TreeNode *maketree(vector<int> &A,int start, int end)
{
    if(start>end) return NULL;
    int maxx = findMax(A,start,end);
    TreeNode *root = new TreeNode(A[maxx]);
    root->left = maketree(A,start,maxx-1);
    root->right = maketree(A,maxx+1,end);
    return root;
    
    
}
TreeNode* Solution::buildTree(vector<int> &A) {
    return maketree(A,0,A.size()-1);
}
