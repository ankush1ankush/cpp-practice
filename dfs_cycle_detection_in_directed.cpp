#include<bits/stdc++.h>
using namespace std;

/* approach is very simple we will take two visited array one to check is node is visited
 and second is to check is cycle in perticular dfs call*/
bool dfs(vector<vector<int>>&G,int s,vector<bool> &visited,vector<bool> &dfsvisit) // dfs to dectect cycle in the 
{  
   
        visited[s]=true;
        dfsvisit[s]=true;
       for(int i=0;i<G.size();i++)
      {
        if(G[s][i]==1&&visited[i]==false)
        {
           
           
           bool ans=dfs(G,i,visited,dfsvisit);
           
           if(ans==true){
            return true;
           }

        }
        else if(G[s][i]==1&&dfsvisit[i]==true&&visited[i]==true)
        {
            return true;
        }
      }
      dfsvisit[s]=false;
   
   return false;

}

bool dfs_directed_cycle_detect(vector<vector<int>>&G)
{
    vector<bool> visited(G.size(),false); // visited array to check node is visited or not
     vector<bool> dfsvisit(G.size(),false);  // vistited  array to check cycle in the dfs call
    for(int i=0;i<G.size();i++)
    {
        if(visited[i]==false)           // need to call dfs to node which visited in any of the dfs call because 
        {                               // we have already check the cycle detection for that node one of the dfs
             bool ans=dfs(G,i,visited,dfsvisit);
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
     
   }
 
   bool ans=dfs_directed_cycle_detect(G);
   
  cout<<ans<<endl;
  
   
   
   cout<<endl;
}