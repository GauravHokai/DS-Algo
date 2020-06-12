int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int Solution::solve(vector<int> &A) {
    int ans = A[0];
    for(int i=1;i<A.size();i++)
    {
        ans = gcd(A[i],ans);
    }
    return ans==1;
}
