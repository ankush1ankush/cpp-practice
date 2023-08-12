#include<bits/stdc++.h>
using namespace std;
 vector<int> bfs(vector<vector<int>> &G, int s, vector<bool> &isvisited )
{
  
  queue<int> q;
  vector<int> distance(G.size(),INT_MAX);
  q.push(s);  

  distance[s]=0;
  while(!q.empty())
  {
    int top=q.front();
    q.pop();
    int dis=distance[top];
    for(int i=0;i<G.size();i++)
    {
        if(G[top][i]==1&& isvisited[i]==false)
        {
             q.push(i);
             if(distance[i]>(dis+1))
             {
                distance[i]=dis+1;
             }
        }
    }
    isvisited[top]=true;
  }
  return distance;
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
 

   vector<bool> isvisited(v,false);
   vector<int> dis(v,INT_MAX);
   dis=bfs(G,0,isvisited);;
   
   for(int i=0;i<dis.size();i++)
   {
    cout<<dis[i]<<" ";
   }
   cout<<endl;
}