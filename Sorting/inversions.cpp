//There are two conditions for the  elements to be inverse:

//arr[i] > arr[j]
//i < j
#include<bits/stdc++.h>
using namespace std;
//using merge sort and counting inversion
int  countandmerge(int arr[], int l, int m, int h){
    
    int n1=m-l+1, n2=h-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];    
    int res=0,i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else{
            arr[k++]=right[j++];
            res+=(n1-i);
        }
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];
    return res;    
}

int countinversions(int A[],int l,int r){
    int res=0;
    if(r>l){
        int m=l+(r-l)/2;
        res+=countinversions(A,l,m);
        res+=countinversions(A,m+1,r);
        res+=countandmerge(A,l,m,r);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int ans=countinversions(A,0,n-1);
    cout<<ans<<endl;
}