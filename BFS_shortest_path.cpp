#include<bits/stdc++.h>
using namespace std;
 vector<int> bfs(vector<vector<int>> &G, int s )
{
  bool isvisited[G.size()]={false};
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
        if(G[s][i]==1&& isvisited[i]==false)
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

