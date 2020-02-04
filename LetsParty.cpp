int mod = 10003;
int Solution::solve(int A) {
    int arr[A+1];
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=A;i++)
    {
        arr[i] = (arr[i-1]%mod + ((i-1) * (arr[i-2]%mod))%mod)%mod;
        
    }
    return arr[A]%10003;
}
