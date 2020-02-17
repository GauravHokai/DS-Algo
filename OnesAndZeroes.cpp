//LEETCODE
class Solution {
public:
    int func(vector<string>& strs, int i, int m, int n,vector<vector<vector<int>>> &dp)
    {
        if(m<0) return -1;
        if (n<0) return -1;
        if(i==strs.size()) return 0;
        /*if(m==0 and n==0)
        {
            if(i==strs.size())
                return 1;
        }*/
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        int zeroes = 0,ones = 0;
        for(int j=0;j<strs[i].length();j++)
        {
            if(strs[i][j]=='0')
                zeroes++;
            else
                ones++;
        }
        //return max(1+func(strs,i+1,m-zeroes,n-ones),func(strs,i+1,m,n));
        dp[i][m][n] =  max(1+func(strs,i+1,m-zeroes,n-ones,dp),func(strs,i+1,m,n,dp));
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return func(strs,0,m,n,dp);
        
    }
};
