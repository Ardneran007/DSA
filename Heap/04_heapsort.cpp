#include<bits/stdc++.h>
using namespace std;
/*Heap sort is modification of selection sort
in selection soer we do linear travel to find max element
her we use concept of max heap to find maximum element
we first build max heap and after building max heap we swap the last element with root of max heap
and do heapify operation(heapify is a operation used when subtrees are heapified and root tree is disturbed)

if we want to sort array in decreasing order use minheap

1.Build a MAx heap(when sort a array in increasing order)
    O(n)
2.Now follow the process like selection sort that is swap the largest elemet with the last element and so on
Now in max heap largest element is at index 0

*/


//Heap sort->Time O(nLogn)
//it is improvement of selection sort
//selction sort worst case->O(n2)
//merge and quick->O(nlogn) they are use more 
//Intro sort algo based on quick sort -uses heap sort
//intro sotr switches to heap sort when recursion depth goes beyond nlogn 

void maxHeapify(int A[],int n,int i)//this is used when root is disturbed
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && A[largest]<A[l])
        largest=l;
    if(r<n && A[largest]<A[r])
        largest=r;//upto this we find largest of root,left child and right child
    if(largest!=i)
    {
        swap(A[i],A[largest]);
        maxHeapify(A,n,largest);
    }
}
//O(n)
void buildMaxheap(int A[],int n)
{
    for(int i=(n/2-1);i>=0;i--)
    {
        maxHeapify(A,n,i);
    }
}

void HeapSort(int A[],int n)
{
    buildMaxheap(A,n);
    for(int i=n-1;i>0;i--)
    {
        swap(A[0],A[i]);
        maxHeapify(A,i,0);//here we are passing i ie we are reducing size of array after every iteration
    }
}
int main()
{
    int A[] = {12, 11, 13, 5, 6, 7}; 
	int n = sizeof(A)/sizeof(A[0]); 

	HeapSort(A, n); 

	cout << "Sorted array is \n";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    } 



    return 0;
}