int func(string A, string B, int i, int j, vector<vector<int>> &dp)
{
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans = 0;
    if(A[i]==B[j])
    {
        ans =  func(A,B,i-1,j-1,dp) + func(A,B,i-1,j,dp);
    }
    else
        ans =  func(A,B,i-1,j,dp);
    dp[i][j] = ans;
    return ans;
}
int Solution::numDistinct(string A, string B) {
    int m = A.length();
    int n = B.length();
    vector<vector<int> > dp(m,vector<int>(n,-1));
    return func(A,B,m-1,n-1,dp);
}
