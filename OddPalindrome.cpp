#define mod 1000000007
vector<int> Solution::solve(string A) {
    string B = A;
    reverse(B.begin(),B.end());
    int n = A.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1])
            {
                dp[i][j] = 1 + (dp[i-1][j]+ dp [i][j-1])%mod;
            }
            else
            {
                dp[i][j] = ((dp[i-1][j] + dp[i][j-1])%mod - dp[i-1][j-1]+mod)%mod;
            }
        }
    }
    vector<int> res(n,0);
    
    for(int i=0;i<n;i++)
    {
        res[i] = (1 + dp[i][n-i-1])%mod;
    }
    return res;
    
}
