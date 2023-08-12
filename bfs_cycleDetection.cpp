#include<bits/stdc++.h>
using namespace std;
bool bfs_cycledetection(vector<vector<int>>G,vector<bool>&isvisited,vector<int>&parent,int s)
{
    queue<int> q;
    q.push(s);
    parent[s]=-1;
    
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        
        for(int i=0;i<G.size();i++)
        {
           if(G[top][i]==1&&isvisited[i]==false&&parent[i]==-1)
           {
            q.push(i);
            parent[i]=top;
            
           }
           if(G[top][i]==1&&isvisited[i]==true&&parent[top]!=i)
           {
            return true;
           }
        }
       isvisited[top]=true;
    }
    return false;
}
bool bfs(vector<vector<int>>&G)
{
   
   vector<int> parent(G.size(),-1);
   vector<bool> isvisited(G.size(),false);
   for(int i=0;i<isvisited.size();i++)
   {
      if(isvisited[i]==false)
      {
        bool ans=bfs_cycledetection(G,isvisited,parent,i);
        if(ans==true)
        {
            return true;
        }
      }
   }
   return false;
}

int main()
{
   int v;
   int e;
   cin>>v;
   cin>>e;

   vector<vector<int>> G(v,(vector<int>(v,0))); 
   for(int i=0;i<e;i++)
   {
      int x,y;
      cin>>x>>y;
      G[x][y]=1;
      G[y][x]=1;
   }
 
   bool ans=bfs(G);
   
  cout<<ans<<endl;
  
   
   
   cout<<endl;
}