//seaarch in rotated sorted array
#include<bits/stdc++.h>
using namespace std;
int search(int A[],int n,int x){
    int lo=0,hi=n-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(A[mid]==x)
            return mid;
        if(A[low]<A[mid])//lsorted
        {
            if(x>=A[lo] && x<A[mid]
                hi=mid-1;
            else
                lo=mid+1;            
        }
        else{
            if(x>A[mid] && x<=A[hi])
                lo=mid+1;
            else
                hi=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    int x;
    cin>>x;
    cout<<search(A,n,x);
}