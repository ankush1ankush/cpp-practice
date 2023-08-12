#include<bits/stdc++.h>
using namespace std;
/*
1)creat reverse the matrix ans simple matrix
2)topological sort node using simple matrix and store them in stack
3)call dfs on the unvisited node in the order in which they are stored in the stack
  and count the strongly connected component.
*/
void dfs_count(vector<vector<int>>&G,int s,vector<bool>&visit) 
{
    visit[s]=true;
    for(int i=0;i<G.size();i++)
    {
        if(G[s][i]==1&&visit[i]==false)
        {
           dfs_count(G,i,visit) ;
        }
    }
    
}

void dfs_sort(vector<vector<int>>&G,int s,stack<int>&T,vector<bool>&visit)
{
    visit[s]=true;
    for(int i=0;i<G.size();i++)
    {
        if(G[s][i]==1&&visit[i]==false)
        {
           dfs_sort(G,i,T,visit) ;
        }
    }
    T.push(s);
}
int main()
{
    int v;
    int e;
    cin>>v;
    cin>>e;
    vector<vector<int>> adj1(v,(vector<int>(v,0))); // simple matrix (directed graph)
    vector<vector<int>> adj2(v,(vector<int>(v,0))); // reversal matrix
    for(int i=0;i<e;i++)
    {
        int m,n;
        cin>>m>>n;
        adj1[m][n]=1; // simple matrix (directed graph)
        adj2[n][m]=1; // reversal matrix
    }
    stack<int> T;
    vector<bool> visit(v,false);
    for(int i=0;i<v;i++)
    {
        if(visit[i]==false)
        {
            dfs_sort(adj1,i,T,visit);
        }
    }
    int count=0;
    for(int i=0;i<v;i++)
    {
        visit[i]=false;
    }
    while(!T.empty())
    {
       int top=T.top();
       if(visit[top]==false)
       {
          dfs_count(adj2,top,visit);
          count++;
       } 
       T.pop();
    }
    cout<<count<<endl;
}