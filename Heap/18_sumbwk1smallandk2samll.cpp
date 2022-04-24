#include<bits/stdc++.h>
using namespace std;

// Given an array of integers and two numbers k1 and k2. Find the sum of all elements between given two k1’th and k2’th smallest elements of the array. It may  be assumed that all elements of array are distinct.

// Example :
// Input : arr[] = {20, 8, 22, 4, 12, 10, 14},  k1 = 3,  k2 = 6  
// Output : 26          
//          3rd smallest element is 10. 6th smallest element 
//          is 20. Sum of all element between k1 & k2 is
//          12 + 14 = 26
int ksmallest(int A[],int n,int k)
{
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(A[i]);
        if(pq.size()>k)
            pq.pop();
    }
    return pq.top();
}
int sum_bw_k1smallestk2smallest(int A[],int n,int k1,int k2)
{
    int Ak1=ksmallest(A,n,k1);
    int Ak2=ksmallest(A,n,k2);
    return Ak1+Ak2;
}

int main() 
{ 
    int arr[] = {1,2,3,4,5};
	int size = sizeof(arr) / sizeof(arr[0]);
    cout<<sum_bw_k1smallestk2smallest(arr,size,5,3);
    return 0;
} 