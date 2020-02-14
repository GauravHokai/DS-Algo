#define mod 1000007
//memoization
// int func(vector<int> &A,int i,int amount,vector<vector<int>> &dp)
// {
//     if(amount==0) return 1;
//     if(amount<0) return 0;
//     if(i<0 and amount>0) return 0;
//     if(dp[amount][i]!=-1)
//         return dp[amount][i];
//     dp[amount][i] = (func(A,i,amount-A[i],dp)%mod + func(A,i-1,amount,dp)%mod)%mod;
//     return dp[amount][i];
// }

//O(MN) space
// int Solution::coinchange2(vector<int> &A, int B) {
//     int m = A.size();
//     vector<vector<int>> dp(B+1,vector<int>(m,0));
//     for(int i=0;i<m;i++)
//     {
//         dp[0][i] = 1;
//     }
//     for(int i=1;i<=B;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             dp[i][j] = (((i-A[j]>=0)?dp[i-A[j]][j]:0)%mod + (j>0?dp[i][j-1]:0)%mod)%mod;
//         }
//     }
     
//     return dp[B][A.size()-1];
// }
//O(B+1) space;
int Solution::coinchange2(vector<int> &A, int B) {
    int m = A.size();
    vector<int> dp(B+1,0);
    dp[0] = 1;
    for(int i=0;i<m;i++)
    {
        for(int j=A[i];j<=B;j++)
        {
            dp[j] = (dp[j]%mod + dp[j-A[i]]%mod)%mod;
        }
    }
    return dp[B];
 
    
}

    
