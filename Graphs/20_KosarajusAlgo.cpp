#include<bits/stdc++.h> 
using namespace std; 
/*
//Here we must do DFS from sink vertex towards source
u-->v
We need to ensure that DFS of v happens first than u.So we need to do preprocessing
-----------------------------------------------------------------------------------
Algo->
1.Order the values in decreasing order of finishing time(Topological sort)
2.Reverse all edges
3.DO Dfs of reverse graph in order obtained in step 1 for every vertex
print all reachale vertices as a string;y connected components
*/

//dfs for toposort
void dfs(int curr,stack<int> &st,vector<int> &visited,vector<int> adj[])
{
    visited[curr]=1;
    for(auto next: adj[curr])
    {
        if(!visited[next])
            dfs(next,st,visited,adj);
    }
    st.push(curr);
}

//dfs for transpose
void revDFS(int node,vector<int> &visited,vector<int> transpose[])
{
    cout<<node<<" ";
    visited[node]=1;
    for(auto next : transpose[node])
    {
        if(!visited[next])
        {
            revDFS(next,visited,transpose);
        }
    }
}


int main()
{
    //Direcred graph input
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    //-----------------------------------------------------
    //STEP 1.Toposort
    stack<int> st;
    vector<int> visited(n,0);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,st,visited,adj);
        }
    }
    
    //STEP 2.
    vector<int> transpose[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;//HERE ITs VERY IMP to remarke visited as 0 as in step 3 we need to do dfs
        for(auto it:adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    //STEP 3
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!visited[node])
        {
            cout<<"SCC: ";
            revDFS(node,visited,transpose);
            cout<<endl;
        }
    }

    return 0;
}
/*
ip

5 5
1 0
0 2
2 1
0 3
3 4



*/