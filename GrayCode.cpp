int bintogray(int num)
{
    return num ^ (num>>1);
}
vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    for(int i=0;i<(1<<A);i++)
    {
        ans.push_back(bintogray(i));
    }
    return ans;
    
}
