#define MOD 1000000007;
// int func(const vector<int> &B,const vector<int> &C,int sum,int i,int cost)
// {
//     if(sum<0) return INT_MAX;
//     if(sum==0) return cost;
//     if(i<0) return INT_MAX;
//     int a = func(B,C,sum-B[i],i,cost+C[i]);
//     int b = func(B,C,sum,i-1,cost);
//     return min(a,b);
// }
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int res = 0;
    vector<int> v(A);
    int maxx = *max_element(v.begin(),v.end());
    vector<vector<int>> dp(maxx+1,vector<int>(B.size()+1,0));
    for(int i=1;i<=maxx;i++)
    {
        dp[i][0] = MOD;
    }
    for(int i=1;i<=maxx;i++)
    {
        for(int j=1;j<=B.size();j++)
        {
            if(i-B[j-1]>=0)
            {
                int cap = B[j-1];
                int cost = C[j-1];
                dp[i][j] = min(dp[i][j-1], cost + dp[i-cap][j]);
                
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    for(auto i:A)
    {
        res = res + dp[i][B.size()];
    }
    return res;
    
}

