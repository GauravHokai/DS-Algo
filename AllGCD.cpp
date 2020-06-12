int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}
int Solution::solve(vector<int> &A) {
    set<int> s;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i;j<A.size();j++)
        {
            int x = gcd(A[i],A[j]);
            s.insert(x);
        }
    }
    return s.size();
}
