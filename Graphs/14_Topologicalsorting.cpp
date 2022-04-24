#include<bits/stdc++.h> 
using namespace std; 
//Directed graph
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}
/*Khans BFS based algorithm
TOPOLOGICAL SORT IS ONLY FOR ACYCLIC GRAPhS*****
if there is cycle of dependencies we cannot do TOpological SOrt
indgree->incomming vertices
here we need to print indegree vertices first

AlGO:
1.Store indegree of every vertex(store it in array)
2.Create a Queue q;
3.Add all 0 indegree vertices to q
4.while(!q.empty())
{
    a.u=q.front() 
        q.pop()
    b.Print u
    c.For every adjacent v of u
        1.Reduce indegree of v by 1
        2.If indegree of v becomes 0 add v to q 
}

Time-> O(V+E) and for storing indegree while traversing the ajlist is O(E)
*/

void Topological_sort(vector<int> adj[],int V)
{
    vector<int> in_degree(V,0);//
    for(int i=0;i<V;i++)//
    {
        for(int x:adj[i])
        {
            in_degree[x]++;
        }
    }

    queue<int> q;
    for(int i=0;i<V;i++)//
    {
        if(in_degree[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        cout<<current<<" ";//
        for(int next:adj[current])
        {
            if(--in_degree[next]==0)//
            {
                q.push(next);
            }
        }
    }
}
int main() 
{ 
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);  
    cout<<" topological SOrt is \n";
    Topological_sort(adj,V);
    return 0; 
} 
