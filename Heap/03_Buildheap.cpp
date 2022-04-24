//CHECK TIME COMPLECITY DERIVATION IT IS BASED ON JEE AGP
#include<bits/stdc++.h>
using namespace std;
//Given a random array rearrange its elements to form MInheap
//MOST IMPORTANT
/*ALGO->
1.Begin with bottomost rightmost internal Node we call minheapify for this then 
call minheapify for i-1 then call minheapify for i-2....i-3,i-4.....0
Bottomost rightmost internal Node is ->Parent of last leaf
ASSUMPTION for calling minheapify function i swhen we call Minheapify for i its left and right must already be heapified
so we are starting from the bottom and going in top direction
2.How to get index of bottomost rightmost internal Node
->a.Last Node will be at size-1
  b.Index of parent of last Node is {(size-1)-1}/2 => (size-2)/2
-----------------------------------------------------------------------------------------------------
Analysis of Time is very important ...just by looking a the funtion we think it is O(nLogn)
but after carefull analysis it comes out to be O(n)
so TIME->O(n)
--DERIVATION(MOST IMPORTANT)
uses fact that --->Maximum Nodes at Height h(where  h is zero at bottom )=upperbound(n/pow(2,h+1))
TOTAL TIME=sumation from{o to logn} of(n/pow(2,h+1))*O(h)
            it comes out to be AGP and after solving it time comes out to be O(n)
*/
class Minheap
{
    int *A;
    int size;
    int capacity;

    public:
    Minheap(int c)
    {
        size=0;
        capacity=c;
        A=new int[c];
    }
    int left(int i){return (2*i+1);}
    int right(int i){return (2*i+2);}
    int parent(int i){return (i-1)/2;}

    void MinHeapify(int i)
    {
        int lt=left(i);
        int rt=right(i);
        int smallest =i;
        if(lt<size && A[lt]<A[i])
            smallest=lt;
        if(rt<size && A[rt]<A[i])
            smallest=rt;
        if(smallest!=i)
        {
            swap(A[i],A[smallest]);
            MinHeapify(smallest);
        }
    }

    void buildHeap()
    {
        for(int i=(size-2)/2;i>=0;i--)//bottomost rightmost internal Node is t index size-2/2
        {
            MinHeapify(i);
        }
    }
   
};
int main()
{
    Minheap h(11);
    return 0;
}