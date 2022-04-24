//DFS based algo
#include<bits/stdc++.h> 
using namespace std; 
//Directed graph
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}
/*
------------------------------------------------------------------------
Important Propert->
here all vertices are printed in decreasing order of finishing time
------------------------------------------------------------------------
1.Create a empty stack

2.For every vertex u do
    if(u is not visited)
        DFS(u,st)

3.while(u is not empty)
    pop an item from stack and print

DFS(u,st)
    1.Mark u as visited
    2.For every adj v of u
        if(v is not visited)
            DFS(u,st)
    3.Push u to stack(once all the dependents of vertex are pushed in stack ew push this vertex in stack)
    ie a Vertex goes into stack only when its dependents are pushed in stack
*/
void DFS(vector<int> adj[],int current,stack<int> &st,bool visited[])
{
    visited[current]=true;

    for(int next:adj[current])
    {
        if(visited[next]==false)
            DFS(adj,next,st,visited);
    }
    st.push(current);//
}   

void Topologicalsort(vector<int> adj[],int V)
{
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }

    stack<int> st;//

    for(int u=0;u<V;u++)
    {
        if(visited[u]==false)
            DFS(adj,u,st,visited);
    }

    while(!st.empty())//
    {
        int u=st.top();
        st.pop();
        cout<<u<<" ";
    }
}

int main() 
{ 
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,1, 3); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 4); 
    addEdge(adj,2, 4);  
    // cout<<" topological SOrt is \n";
    Topologicalsort(adj,V);
    return 0; 
} 
/*
0        2
|        | \
↓        ↓   ↘
1-------→3----→4

Recursion tree diagram
DFS(0)                          DFS(2)
    DFS(1)                          st.push(2)
        DFS(3)
            DFS(4)
                st.push(4)
            st.push(3)
        st.push(1)
    st.push(0)
*/