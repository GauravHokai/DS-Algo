int Solution::adjacent(vector<vector<int> > &A) {
    vector<int> maxx;
    for(int i=0;i<A[0].size();i++)
    {
        maxx.push_back(max(A[0][i],A[1][i]));
    }
    int ans[maxx.size()+1];
    ans[1] = maxx[0];
    ans[2] = max(maxx[0],maxx[1]);
    for(int i=3;i<=maxx.size();i++)
    {
        ans[i] = max(maxx[i-1]+ans[i-2],ans[i-1]);
    }
    return ans[maxx.size()];
}
