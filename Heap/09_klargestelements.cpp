#include<iostream>
#include<queue>
using namespace std;

//method 1.sort and traverse nlogn
//methd 2.MAXheap O(n){inserting in queue} + O(k*logn){removing item from heap is logn}==O(n+klogn)
/*method 3.a.Build min heap of first k elements//O(k)
           b.Traverse from k+1 element//O((n-k)*logk)
                1.compare current elemet with top if small then ignore it
                2.Else remove the top element and insert thte current elemetn in the minheap
            c.Print contents of min heap//O(k)
        LOOP INVARIENTS IN THE METHOD-> at any moments we have k largest elements seen so far
        Overall time->>O(k + (n-k)* logk)
*/
//MAXheap->O(n + klogn)
//minheap->O(k + (n-k)* logk)-->this is better for corner as well as in general(take k as 1 and k and n-1..)
void firstKElements(int A[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int> >pq;//imnheap
    for(int i=0;i<k;i++)//O(k)
    {
        pq.push(A[i]);
    }
    for(int i=k;i<n;i++)//O((n-k)*logk)
    {
        if(pq.top()<A[i])
        {
            pq.pop();
            pq.push(A[i]);
        }
    }
    while(pq.empty()==false)//O(k)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

//same appraoach another syntax
void klargest(int A[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int> >pq;//imnheap
    for(int i=0;i<n;i++)
    {
        pq.push(A[i]);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    while(pq.empty()==false)//O(k)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main() 
{ 
    int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int k = 3;
    for(int k=1;k<size;k++)
    {
        cout<<"printing first "<<k <<" greater elements\n";
	firstKElements(arr,size,k);
    cout<<endl;
    }
    klargest(arr,size,k);
 
    return 0;
} 
