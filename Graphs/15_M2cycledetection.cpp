//Here this is just a modification of Kahns algo
//using the FACT->Topological Sort works only when the graph does not contain any cycles
#include<bits/stdc++.h> 
using namespace std; 
//Directed graph
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}
/*Khans BFS based algorithm
indgree->incomming vertices
here we need to print indegree vertices first

we increment the count whenever we popout vertex from q
and at last if q==V then it is not cyclic

AlGO:
1.Store indegree of every vertex(store it in array)
2.Create a Queue q;
3.Add all 0 indegree vertices to q
4.Count=0
4.while(!q.empty())
{
    a.u=q.front() 
        q.pop()
    b.For every adjacent v of u
        1.Reduce indegree of v by 1
        2.If indegree of v becomes 0 add v to q 
    c.count++;
}
6.return (count!=V)
Time-> O(V+E) and for storing indegree while traversing the ajlist is O(E)
*/

void Topological_sort(vector<int> adj[],int V)
{
    vector<int> in_degree(V,0);
    for(int i=0;i<V;i++)
    {
        for(int x:adj[i])
        {
            in_degree[x]++;
        }
    }

    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(in_degree[i]==0)
            q.push(i);
    }
    int count=0;
    while(!q.empty())
    {
        int current=q.front();
        q.pop();//here count is incremented 
        // cout<<current<<" ";
        for(int next:adj[current])
        {
            if(--in_degree[next]==0)
            {
                q.push(next);
            }
        }
        count++;//this is incremented when we take out an item from queue
    }

    if(count!=V)
        cout<<"There is a cycle in graph\n";
    else
        cout<<"NO cycle\n";
}
int main() 
{ 
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,4, 1); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1); 
    // cout<<" topological SOrt is \n";
    Topological_sort(adj,V);
    return 0; 
} 
