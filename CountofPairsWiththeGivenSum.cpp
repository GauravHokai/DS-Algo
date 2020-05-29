int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    int i=0,j=A.size()-1;
    while(i<j)
    {
        if(A[i] + A[j]==B)
        {
            ans++;
            i++;
        }
        else if(A[i]+A[j]<B)
        {
            i++;
        }
        else
        {
            i++;
            j--;
        }
        
    }
    return ans;
}
