//Minimum spanning Tree
#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

int PrimMst(int graph[V][V])
{
    int key[V];
    int res=0;
    bool mSet[V];
    key[0]=0;

    for(int count=0;count<V;count++)
    {
        int u=-1;

        for()
    }
}







//--------------------------------------------------------------------------------------------------
/*
No of Spanning Tree-> (E)C(V-1) - no of cycles
min cost spanning tree->
a.Prims ago 
    Initaially select the smallest edge and then always select the connected smallest one
For non connected graph no spanning tree are possible
proof of prims->check book(not in Sahani)
Prims algo is good than kruskal as detection of cycle is not that ....


b.Kruskals algo
    Always select the min cost edge but if it is forming cycle dont include it in soln
theta(V*E)->theta(n2)
observation:
a.N-1 edges is essential in such a way that tree is not formed
b.smallest edges are present in it 
we can use min heap to keep always min value
theta(n *logn)
#Kruskal algo may work for diconnected ie it may give spanning tree for any of the component
ALso check proof given in class

Q.check questions of min cost of missing edge in spanning tree

*/