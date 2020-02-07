bool isperfect(int n)
{
    double m = sqrt(n);
    if((m-floor(m))==0)
        return 1;
    return 0;
}
int Solution::countMinSquares(int A) {
    //if(isperfect(A)) return 1;
    int dp[A+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4;i<=A;i++)
    {
        dp[i] = i;
        if(isperfect(i))
        {
            dp[i] = 1;
        }
        else
        {
            for(int j = 1;j*j<=i;j++)
            {
                int x = j*j;
                dp[i] = min(dp[i],1+dp[i-x]);
            }
            
        }
        
    }
    return dp[A];
}
