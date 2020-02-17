//LEETCODE
#define mod 1000000007
class Solution {
public:
    int func(int m, int n, int N, int i, int j,vector<vector<vector<int> > > &dp)
    {
        if(i<0 or j<0 or i>=m or j>=n)
            return 1;
        if(N<=0) return 0;
        if(dp[i][j][N]!=-1)
            return dp[i][j][N]%mod;
        int a = (func(m,n,N-1,i+1,j,dp)%mod + func(m,n,N-1,i-1,j,dp)%mod)%mod;
        int b = (func(m,n,N-1,i,j+1,dp)%mod + func(m,n,N-1,i,j-1,dp)%mod)%mod;
        dp[i][j][N] = (a%mod + b%mod)%mod;
        return dp[i][j][N]%mod;
     
    }
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m+1,(vector<vector<int>>(n+1,vector<int>(N+1,-1))));
        return func(m,n,N,i,j,dp);
    }
};
