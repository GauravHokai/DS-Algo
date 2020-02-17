int Solution::minimumTotal(vector<vector<int> > &A) {
    int n = A.size();
    vector<int> res(A.back());
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<A[i].size();j++)
        {
            res[j] = min(res[j],res[j+1]) + A[i][j];
        }
    }
    return res[0];
    
}
