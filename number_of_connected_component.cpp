#include<bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>>&G,int s,vector<bool> &isvisited)
{
    queue<int> q;
    q.push(s);
    isvisited[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<G.size();i++)
        {
            if(G[u][i]==1&&isvisited[i]==false)
            {
                q.push(i);
                isvisited[i]=true;
            }
        }
        cout<<u<<" ";
    } 
    cout<<endl;
}
void BFS_connected_component(vector<vector<int>>&G)
{
    vector<bool> isvisited(G.size(),false);
    int count=0;
    for(int i=0;i<G.size();i++)
    {
        if(isvisited[i]==false)
        {
           count++;
           cout<<"connected component : "<<count<<endl;
           BFS(G,i,isvisited);

        }
    }
    cout<<"Number of connected component"<<endl;
    cout<<count<<endl;
}
int main()
{
   int n,e;
   cin>>n>>e;

   vector<vector<int> > matrix(n,vector<int>(n,0));

   for(int i=1;i<=e;i++){
    int fv,sv;
    cin>>fv>>sv;
    matrix[fv][sv] = 1;
    matrix[sv][fv] = 1;
   }
   BFS_connected_component(matrix);
}