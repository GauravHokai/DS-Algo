#define mod 1000000007
int Solution::solve(vector<int> &A, int B) {
    vector<int> temp(B,0);
    int ans = 0;
    for(int i=0;i<A.size();i++)
    {
        temp[A[i]%B]++;
    }
    for(int i=0;i<B;i++)
    {
        for(int j=i;j<B;j++)
        {
            int rem = (B-(i+j)%B)%B;
            if(rem<j)   continue;
            if(i==j and j==rem)
                ans = (ans + (temp[i]*(temp[i]-1)*(temp[i]-2)/6))%mod;
            else if(i==j)
                ans = (ans + (temp[i]*(temp[i]-1)*temp[rem]/2))%mod;
            else if(i==rem)
                ans = (ans + (temp[i]*(temp[i]-1)*temp[j]/2))%mod;
            else if(j==rem)
                ans = (ans + (temp[j]*(temp[j]-1)*temp[i]/2))%mod;
            else
                ans =(ans + temp[i]*temp[j]*temp[rem])%mod;
        }
    }
    return ans;
    
}
