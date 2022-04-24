#include<bits/stdc++.h>
using namespace std;
//Naive
void printCeiling(int A[],int n)
{
    cout<<"-1 ";
    for(int i=1;i<n;i++)
    {
        int diff=INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(A[j]>=A[i])
                diff=min(diff,A[j]-A[i]);
        }
        if(diff==INT_MAX)
            cout<<"-1 ";
        else
            cout<<(A[i]+diff)<<" ";
    }
}

//optimised->create SBST(SETS)
void printCeiling_optimised(int A[],int n)
{
    set<int> s;
    s.insert(-1);
    for(int i=1;i<n;i++)
    {
        if(s.lower_bound(A[i])!=s.end())
            cout<<*(s.lower_bound(A[i]))<<" ";
        else
            cout<<"-1 ";
            s.insert(A[i]);
    }
}
int main()
{
    int arr[]={2,8,30,15,25,12};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	printCeiling(arr,n);
    cout<<"\n";
    printCeiling_optimised(arr,n);
    
}
