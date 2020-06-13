vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> res(A,0);
    for(int i=0;i<B.size();i++)
    {
        int l = B[i][0]-1;
        int r = B[i][1];
        int val = B[i][2];
        res[l] = res[l] + val;
        if(r<A) res[r] = res[r] + (-1)*val;
    }
    int ans = 0;
    for(int i=0;i<A;i++)
    {
        res[i] = ans + res[i];
        ans = res[i];
    }
    return res;
}
