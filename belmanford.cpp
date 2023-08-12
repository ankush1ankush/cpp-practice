#include <bits/stdc++.h>
using namespace std;

void bellman_ford(vector<vector<int>> &edges, int v)
{
    vector<int> dist(v, INT_MAX);
    dist[0] = 0;

    for (int i = 1; i <= v - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (dist[u] != INT_MAX && (dist[u] + w < dist[v]))
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool isNegCycle = false;
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if (dist[u] != INT_MAX && (dist[u] + w < dist[v]))
        {
            isNegCycle = true; 
            break;
            dist[v] = dist[u] + w;
        }
    }
    if(isNegCycle == true) cout<<"Negative Cycle - not possible"<<endl;
    for(int i=0;i<v;i++) {
        cout<<"Distance from 0 to "<<i<< " : "<<dist[i]<<endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter u - v - w"<<endl;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> v >> u >> w;
        edges.push_back({u, v, w});
    }

    bellman_ford(edges, n);

    return 0;
}
