bool valid(string a)
{
    int ans = stoi(a);
    //cout<<ans<<endl;
    if(ans>=10 and ans<=26)
        return 1;
    return 0;
}
int Solution::numDecodings(string A) {
    int arr[A.length()+1];
    if(A.substr(0,1)=="0") return 0;
    arr[1] = 1;
    if(A.substr(1,1)=="0")
    {
        arr[2] = valid(A.substr(0,2));
    }
    else
        arr[2] = 1 + valid(A.substr(0,2));
    for(int i=3;i<=A.length();i++)
    {
        int x = 0;
        int y = 0;
        if(A.substr(i-1,1)=="0")
            y=0;
        else
        {
            y = arr[i-1];
        }
        if(valid(A.substr(i-2,2)))
            x = arr[i-2];
        arr[i] = y + x;
    }
    /*for(int i=1;i<=A.length();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/
    return arr[A.length()];
}

