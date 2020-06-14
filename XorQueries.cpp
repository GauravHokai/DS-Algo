vector<vector<int> > Solution::solve(vector<int> &A, vector<vector<int> > &B)
{
    vector<vector<int> > ans;
    vector<int> res(A.size()+1,0);
    for(int i=1;i<=A.size();i++)
    {
        res[i] = res[i-1] + A[i-1];
    }
    for(int i=0;i<B.size();i++)
    {
        int l = B[i][0];
        int r = B[i][1];
        int ones,_xor = 0;
        vector<int> temp;
        ones = res[r]-res[l-1];
        if(ones&1)
        {
            _xor = 1;
        }
        temp.push_back(_xor);
        temp.push_back(r-l+1-ones);
        ans.push_back(temp);
    }
    return ans;
}
