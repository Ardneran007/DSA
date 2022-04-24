#include<iostream>
#include<queue>
using namespace std;
//priority queue uses heap but they are build on top of vectors
//priority queue uses heap it by default uses (MAX heap) 
//so the maximum element is always at the top 
/*Applications
1.DIjkstra Algo
2.Prim Algo
3.Huffman Algo
4.Heap Sort
5.And places wheer heap is used
*/
int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    // pq.push(0);
    cout<<"size->"<<pq.size()<<"\n";
    while(pq.empty()==false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }

    //---------------------------------------------
    //if we want minimum element at the top we use the following syntax
    cout<<"\nreverse priority queue\n";
    priority_queue<int,vector<int>,greater<int> > rpq;//this gives top as minimum{here in place of greater int we can use oour own algo}
//priority queue uses heap but they are build on top of vectors
    rpq.push(3);
    rpq.push(1);
    rpq.push(2);
    // cout<<pq.top();
    while(rpq.empty()==false)
    {
        cout<<rpq.top()<<" ";
        rpq.pop();
    }
    //------------------------------------------------------------------
    //create priority queue from vector array 
    cout<<"\nPriority queue from array using constructor\n";
    int A[]={100,800,900,1};
    priority_queue<int> pqa(A,A+4);//this is always better than pushing and creating a priority queue as make heap is of O(n)
    while(pqa.empty()==false)
    {
        cout<<pqa.top()<<" ";
        pqa.pop();
    }

}
//top,empty,size->O(1)
//push,pop->log(n)
//way of constructing priority queue from vector is O(n)
//if we are creating priority queue of pairs then elements will be on basis of 1st element
//