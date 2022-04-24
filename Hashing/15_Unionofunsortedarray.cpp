#include<bits/stdc++.h>
using namespace std;

//distinct elements in Union of two unsorted arrays
//time->theta(m+n)
//space->O(m+n)
int distinct_union(int A[],int B[],int n,int m)
{
    unordered_set<int> a;
    for(int i=0;i<n;i++)
        a.insert(A[i]);
    for(int i=0;i<m;i++)
        a.insert(B[i]);
    return a.size();
}
int main()
{
    int A[] = {2, 8, 3, 5, 6};
    int B[] = {4, 8, 3, 6, 1};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    cout<<distinct_union(A,B,n,m);
    return 0;

}
