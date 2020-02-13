int Solution::solve(string A, string B) 
{
    vector<vector<int> > res(A.length()+1,(vector<int>(B.length()+1,0)));
    for(int i=1;i<=A.length();i++)
    {
        for(int j=1;j<=B.length();j++)
        {
            if(A[i-1]==B[j-1])
            {
                res[i][j] = 1 + res[i-1][j-1];
            }
            else
            {
                res[i][j] = max(res[i-1][j],res[i][j-1]);
            }
        }
    }
    return res[A.length()][B.length()];
    
}
