int func(int A)
{
    int arr[A+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=A;i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[A];
}

int Solution::climbStairs(int A) {
    return func(A);
    
}
