#include<bits/stdc++.h>
using namespace std;
/*
theta(n2) worst case(reverse sorted)need to do max shifting in all iteration :(
theta(n) BEST CASE(Already sorted)
in general->O(n2)
Inplace + stable
Preferred for small array (used in TIMSORT and INTROSORT)

IDEA:
Maintain 2 part [ SORTED |KEY UNSORTED]
When at index i elemnts from 0  i-1 a sorted and i to n-1 are not sorted
INsert at correct position

*/
void insertionsort(int A[],int n){
    for(int i=1;i<n;i++){//begin with second element and insert at its correct position
        int key=A[i];
        int j=i-1;
        while(j>=0 && A[j]>key){//while key is smaller then only we will run the loop
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;//when we odnt go inside while loop the value is going to override itself
    }
}
//here there is o equal to sign A[j]>key so it is stable but if we put A[j]>=key then its bcomes unstable
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    insertionsort(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}