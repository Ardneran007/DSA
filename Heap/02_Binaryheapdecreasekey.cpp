#include<bits/stdc++.h>
using namespace std;

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
    //-----------------------------------------------------------------------------------------------------------
    /*While inserting the properties of MIn heap must not be violated
    here we first insert the vaue at the end of array 
    then we check it with its parent if it is small we swap them 
    //time->O(log(height))
    */
    void insert(int x)
    {
        if(size==capacity)
            return;
        size++;
        A[size-1]=x;
        for(int i=size-1;i!=0 && A[parent(i)]>A[i];)//here parent must be smaller ie if it is greater we swap those ....(not to do i++)
        {
            swap(A[i],A[parent(i)]);
            i=parent(i);//hree i is updated
        }
    }
    //-----------------------------------------------------------------------------------------------------------
    /* Min Heap->Given a Binary Heap with one possible vioation fix the heap;
    Heapify operation->Given a Min Heap there may be only one NOde violating the Min Heap Property so we need to fix it
    
    (heapify is a operation used when subtrees are heapified and root tree is disturbed)

    Idea->1.compare root,left child,right child minimum must be at root be minimum is not at root and it is in one 
            of its children we swap the root and that children and call recursively for that child
    Time->O(h)~O(logn)
    space->O(h)
    */
   void MinHeapify(int i)
   {
       int lt=left(i);
       int rt=right(i);
       int smallest=i;
       if(lt<size && A[lt]<A[i])//here lt<size means we are checking that if left child exists
       {
           smallest=lt;
       }
       if(rt<size && A[rt]<A[i])//here rt<size means we are checking if right child exists
       {
           smallest=rt;
       }
       if(smallest!=i)
       {
           swap(A[i],A[smallest]);
           MinHeapify(smallest);//calling the func recursively for the node which is swapped
       }
   }

    //-----------------------------------------------------------------------------------------------------------
    /*Extract Minimum
    1.swap the first element with the last and do 
        ie-> a.swap(A[0],A[size-1)  b.size--
    2.Call heapify for the new Root
    Time->O(logn){due to heapify func}
    Space->O(logn){depends on how we write heapify functio}
    */
    int extractMin()//removes min item from heap
    {
        if(size==0) 
            return INT_MAX;
        if(size==1)
        {
            size--;
            return A[0];
        }
        swap(A[0],A[size-1]);
        size--;
        MinHeapify(0);
        return A[size];//returns the removed item
    }

    //-----------------------------------------------------------------------------------------------------------
    //Decrease the Heap ->a index will be given and a target value we need to update the indexs value to target
    /*
    after we update the value we need the Properties of MIn heap to be followed
    Algo->
    1.Go to index and change the value
    2.After changing the value do something like Insert,compare the value to its parent and if parent is greater swap 
    the values
    3.Keep doing this while parent is greater or we reach root 
    TIme->O(log N)
    */
   void decreasekey(int i,int x)
   {
       A[i]=x;
       while(i!=0 && A[parent(i)]>A[i])//we keep doing this until we dont reach the NOde && parent is bigger than child
       {
           swap(A[i],A[parent(i)]);
           i=parent(i);
       }
   }
    //-----------------------------------------------------------------------------------------------------------
    /*
    Delete function calls decresekey that is to be deleted to -infinite and aftre that we do extract minimum
    
    O(logn)*/
   void deleteKey(int i)
   {
       decreasekey(i,INT_MIN);//after decrease key does its work -Inf goes to the top root
       extractMin();

   }
};
int main()
{
    Minheap h(10);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
    cout<<"minimum by usig extractmin before updation : "<<h.extractMin()<<" \n";
    h.decreasekey(2,1);
    cout<<"minimum by usig extractmin after updation : "<<h.extractMin()<<" ";
    h.deleteKey(1);
    cout<<h.extractMin();
    return 0;
}