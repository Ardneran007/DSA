#include<bits/stdc++.h>
using namespace std;
/*
Bridges-THose edges on whose removal from graph the graph is broken in two or more components
low[i]->lowest reachable discovery time
For u-v to be a bridge
low[u]>dis[v](time of insertion)
*/

void dfs(int node,int parent,vector<int> &visited,vector<int> &tin,vector<int> &low,int &timer,vector<int> adj[])
{
    visited[node]=1;
    tin[node]=low[node]=timer++;
    for(auto it:adj[node])
    {
        if(it==parent)
            continue;
        
        if(!visited[it])
        {
            dfs(it,node,visited,tin,low,timer,adj);
            low[node]=min(low[node],low[it]);
            if(low[it] > tin[node])
            {
                cout<<node<<" "<<it<<endl;
            }
        }
        else//
        {
            low[node]=min(low[node],tin[it]);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n,-1);//time of insertion
    vector<int> low(n,-1);
    vector<int> visited(n,0);
    int timer=0;
    cout<<"Bridges\n";
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            dfs(i,-1,visited,tin,low,timer,adj);
    }

    return 0;
}
/*

5 5
1 0
0 2
2 1
0 3
3 4 



*/