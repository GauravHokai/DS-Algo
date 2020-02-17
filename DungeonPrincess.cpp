int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> dp(m+1,(vector<int>(n+1,INT_MAX)));
    dp[m-1][n] = 1;
    dp[m][n-1] = 1;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            int x = min(dp[i+1][j],dp[i][j+1]) - A[i][j];
            dp[i][j] = x>0?x:1;
        }
    }
    return dp[0][0];
    
}
