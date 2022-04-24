#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;//n-no of nodes ,m-no of edges
    //Undirected
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        vin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //-----------------------------------------------------------------
    //Directed
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        vin>>u>>v;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    //-----------------------------------------------------------------
    //weighted
    vector<pair<int,int> > adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        vin>>u>>v>>wt;

        adj[u].push_back({v,wt});
        adj[v].push_back({v,wt});
    }
}