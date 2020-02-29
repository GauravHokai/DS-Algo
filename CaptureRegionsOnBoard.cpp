void makechanges(vector<vector<char> > &A,int i,int j)
{
    if(A[i][j]=='O')
    {
        A[i][j] = '1';
        if(i>1) makechanges(A,i-1,j);
        if(j>1) makechanges(A,i,j-1);
        if(i+1<A.size()) makechanges(A,i+1,j);
        if(j+1<A[0].size()) makechanges(A,i,j+1);
    }
    
}
void Solution::solve(vector<vector<char> > &A) {
    int rows = A.size();
    int cols = A[0].size();
    for(int i=0;i<rows;i++)
    {
        makechanges(A,i,0);
        makechanges(A,i,cols-1);
    }
    for(int i=1;i<cols;i++)
    {
        makechanges(A,0,i);
        makechanges(A,rows-1,i);
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(A[i][j]=='O')
                A[i][j] = 'X';
            else if(A[i][j]=='1')
                A[i][j] = 'O';
        }
    }

}
