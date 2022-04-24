#include<bits/stdc++.h>
using namespace std;
//time->theta(n)//but what if n is very large and k is very small 
//in such case this solution is not good 
void printoccmorethannbyk(int A[],int n,int k)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[A[i]]++;
    }
    for(auto it:m)  
    {
        if(it.second>n/k)
            cout<<it.first<<" ";
    }
}
int main()
{
    int arr[] = {10, 10, 20, 30, 20, 10,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    printoccmorethannbyk(arr,n,k);
    return 0;

}
