//imp -> company tages->fipkart
#include<iostream>
#include<queue>
using namespace std;
//sort a k sorted array 
//given n array and k the position of element A[i] in sorted array lies b/w i-k to i+k

//naive sort(A,A+n)->nlogn
//IMP->if we want to sort array in increasing order use MINHEAP
//sort in decreasing order ->use MAXHEAP

//here we use minheap*
//time->O(klogk)
void sortk(int A[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int> >pq;//creating min heap
    //klogk
    for(int i=0;i<=k;i++)
    {
        pq.push(A[i]);
    }//pushing k+1 items in min heap
    int index=0;
    //(n-k)logk
    for(int i=k+1;i<n;i++)//traversing minim item
    {
        A[index++]=pq.top();//taking out element form the heap and adding at the index and inxrementing the index
        pq.pop();
        pq.push(A[i]);
    }
    //klogk
    while(pq.empty()==false)//adding the remianing elements
    {
        A[index++]=pq.top();
        pq.pop();
    }
}
int main()
{
    int k = 3; 
	int arr[] = { 2, 6, 3, 12, 56, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	sortk(arr, n, k); 

	cout << "Following is sorted array" << endl; 
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
