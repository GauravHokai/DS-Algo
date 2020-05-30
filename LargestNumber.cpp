bool myCompare(string X, string Y) 
{
	return X+Y>Y+X;
} 
string Solution::largestNumber(const vector<int> &A) {
    vector<string> vec;
    for(int i=0;i<A.size();i++)
    {
        vec.push_back(to_string(A[i]));
    }
    sort(vec.begin(),vec.end(),myCompare);
    string ans;
    for(int i=0;i<A.size();i++)
    {
        ans.append(vec[i]);
    }
    int index=0;
    while(ans[index]=='0' and index+1<ans.size()) index++;
    return ans.substr(index);
}
