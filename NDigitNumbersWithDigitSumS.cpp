#define mod 1000000007
int func(int A, int B, vector<vector<int>> &dp)
{
    if(A==0) return B==0;
    if(B==0) return 1;
    if(dp[A][B]!=-1)
        return dp[A][B];
    int ans = 0;
    for(int i=0;i<=9;i++)
    {
        if(B-i>=0)
            ans = (ans + func(A-1,B-i,dp))%mod;
    }
    return dp[A][B] = ans;
}
int Solution::solve(int A, int B) {
    int ans = 0;
    vector<vector<int>> dp(A,vector<int>(B,-1));
    for (int i = 1; i <= 9; i++)
    {
        if (B-i >= 0) 
            ans = (ans + func(A-1, B-i, dp))%mod;
    }
  
    return ans;
}
