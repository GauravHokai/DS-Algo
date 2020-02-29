// int checkrem(string t, int n)
// {
//     int r = 0;
//     for(int i=0;i<t.length();i++)
//     {
//         r = r*10 + (t[i]-'0');
//         r = r%n;
//     }
//     return r;
// }
// string Solution::multiple(int A) {
//     queue<string> q;
//     set<int> s;
//     string str = "1";
//     q.push(str);
//     while(!q.empty())
//     {
//         str = q.front();
//         q.pop();
//         int rem = checkrem(str,A);
//         if(rem==0) return str;
//         else if(s.find(rem)==s.end())
//         {
//             s.insert(rem);
//             q.push(str+"0");
//             q.push(str+"1");
//         }
        
//     }
    
// }

string Solution::multiple(int A)
{
    queue<int> q;
    
    q.push((1%A));
    vector<int> vis(A+1,-1);
    vis[1%A]=1;
    vector<pair<int,char>> par(A+1,{-1,'1'});
    while(!q.empty())
    {
       int tp = q.front();
       q.pop();
       if(tp==0)
       {
           string s="";
           s+=par[0].second;
           int p = par[0].first;
           while(p!=-1)
           {
               s+=par[p].second;
               p = par[p].first;
               
           }
           reverse(s.begin(),s.end());
           return s;
       }
       int a1 = (tp*10)%A;
       int a2 = ((tp*10)%A+1)%A;
       if(vis[a1]==-1)
       {
           q.push(a1);
          
           vis[a1] =1;
           par[a1] = {tp,'0'};
           
       }
       if(vis[a2]==-1)
       {
           q.push(a2);
           vis[a2]=1;
           par[a2] = {tp,'1'};
           
       }
    }
    
    
}
