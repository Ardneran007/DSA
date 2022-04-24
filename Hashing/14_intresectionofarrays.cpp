#include<bits/stdc++.h>
using namespace std;
//optimised
//time->theta(n)
//space->O(n)
//Q.distinct common elements

//efiicient solution 1
//here we create 2 sets 
int distinctcommon(int A[],int B[],int n,int m)
{
    int count=0;
    unordered_set<int> a(A,A+n);
    unordered_set<int> b(B,B+n);
    for(auto it:a)
    {
        if(b.find(it)!=b.end())
        {
            count++;
        }
    }
    return count;
}

//optimised solution 2
//here we create only one set and put all elements of a in it
//and now we traverse B[] search for every element of B[] in s_a
//if present
//1.Increment a
//2.remove B[i] from s_a {this is imp to avoid duplicates}
int distinctcommon_optimised(int A[],int B[],int n,int m)
{
    int count=0;
    unordered_set<int> s_a(A,A+n);
    for(int i=0;i<m;i++)
    {
        if(s_a.find(B[i])!=s_a.end())
        {
            count++;
            s_a.erase(B[i]);//this is done to remove duplicates
        }
    }
    return count;
}
int main()
{
    int A[] = {15, 17, 27, 27, 28, 15};
    int B[] = {16, 17, 28, 17, 31, 17};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    cout<<distinctcommon(A,B,n,m)<<"\n";
    cout<<distinctcommon_optimised(A,B,n,m)<<"\n";
    return 0;

}
