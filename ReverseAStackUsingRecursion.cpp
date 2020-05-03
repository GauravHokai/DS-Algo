void func(vector<int> &A, int i, vector<int> &ans)
{
    if(i==A.size()) return;
    func(A,i+1,ans);
    ans.push_back(A[i]);
    return;
    
}
vector<int> Solution::solve(vector<int> &A) {
    if(A.size()==0) return {};
    vector<int> ans;
    func(A,0,ans);
    return ans;
}
