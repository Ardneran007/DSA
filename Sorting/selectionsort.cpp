#include<bits/stdc++.h>
using namespace std;
/*
Comparision based algoritm and has theta(n2) time in all cases
less memory writes comapred to other algorithm
NOT STABLE + INPLACE

Basis Idea:
Find out first Minimum element and put at first ,find out second minimum and put at second

At every point maining two half of array as First half which is already sorted
and second half which is yet to be sorted


TIME->n-1 +  n-2  +  n-3  +     1 -> theta(n2)
always takes n2
*/
void selectionsort(int A[],int n){
//elements from 0 to i are mainted to be sorted and elemnts from i to n-1 are not sorted

    for(int i=0;i<n-1;i++){//as only 1 elemt left so running till n-1
        int min_indx=i;
        for(int j=i+1;j<n;j++){//Finding out minimum element in renmaining array(from i+1 to n-1)
            if(A[j]<A[min_indx]){
                min_indx=j;
            }
        }
        swap(A[min_indx],A[i]);
    }
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    selectionsort(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}