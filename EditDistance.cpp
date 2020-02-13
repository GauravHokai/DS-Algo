int func(string A, string B, int i, int j,vector<vector<int>> &dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans = -1;
    if(A[i]==B[j])
        ans =  func(A,B,i-1,j-1,dp);
    else
    {
        ans =  min(1 + func(A,B,i,j-1,dp),min(1+ func(A,B,i-1,j-1,dp),1+func(A,B,i-1,j,dp)));
    }
    dp[i][j] = ans;
    return ans;
        
}
int Solution::minDistance(string A, string B) {
    int m = A.length();
    int n = B.length();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return func(A,B,m-1,n-1,dp);
}
