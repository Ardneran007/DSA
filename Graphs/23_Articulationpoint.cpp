#include<bits/stdc++.h>
using namespace std;
/*
Articulation point- A point is called a Articulation pt if deleteing that point the graph will broken down in 2 or more ocmponents

conditions
1.low[it]>=time[node] && parent!=-1
2.if(parent==-1 &7 child>1)//this is for the parent node
Time-O(V+E)
space-O(N)

*/

void dfs(int node,int parent,vector<int> &visited,vector<int> &tin,vector<int> &low,int &timer,vector<int> adj[], vector<int> &isArticulation)
{
    visited[node]=1;
    tin[node]=low[node]=timer++;
    int child=0;
    for(auto it:adj[node])
    {
        if(it==parent)
            continue;
        
        if(!visited[it])
        {
            dfs(it,node,visited,tin,low,timer,adj,isArticulation);
            low[node]=min(low[node],low[it]);
            child++;
            if(low[it] >= tin[node] && parent!=-1)//
            {
                isArticulation[node]=1;
            }
        }
        else//
        {
            low[node]=min(low[node],tin[it]);
        }
    }
    if(parent==-1 && child>1)//this is for the root node 
        isArticulation[node]=1;
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
    vector<int> isArticulation(n,0);
    int timer=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            dfs(i,-1,visited,tin,low,timer,adj,isArticulation);
    }

    cout<<"Articulation pt\n";
    for(int i = 0;i<n;i++) {
	    if(isArticulation[i] == 1) cout << i << endl;
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