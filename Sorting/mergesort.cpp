#include<bits/stdc++.h>
using namespace std;
/*
Divide and Conquer algo
STABLE sorting 
theta(nlogn)
bAD THING-> O(n) exra space :(
quick sort works better than merge sort for Arrays only    


IDEA:
use 2 pointers

first check if ip array contains atleast 2 elements
recursively call mergesort for left half and then right half and then merge the 2 halfs
Analysis:
height/No of levels->ceil(logn)
TIme->theta(nlogn)
Space->theta(n) At any moment theta n space is required not nlogn
*/

void merge(int arr[], int l, int m, int h){
    
    int n1=m-l+1, n2=h-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];    
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])//= for stable sorting
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];    
}

void mergesort(int A[],int l,int r){
    if(r>l){//atleast 2 elelemtns
        int m=l+(r-l)/2; //same as l+r/2 but writing this to avoid overflow
        mergesort(A,l,m);
        mergesort(A,m+1,r);
        merge(A,l,m,r);
    }
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    mergesort(A,0,n-1);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}