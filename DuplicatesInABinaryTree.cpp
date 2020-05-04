/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
string func(TreeNode *root, unordered_map<string ,int> &u_map)
{
    if(!root) return "";
    string str = to_string(root->val) + "," + func(root->left,u_map) + "," + func(root->right,u_map);
    u_map[str]++;
    return str;
}
int Solution::solve(TreeNode* A) {
    unordered_map<string,int> u_map;
    func(A,u_map);
    for(auto i:u_map)
    {
        if(i.first.length()>=4 and i.second>=2)
        {
            return 1;
        }
    }
    return 0;
    
}
