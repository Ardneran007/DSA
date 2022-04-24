#include<bits/stdc++.h>
using namespace std;
//worst case->O(2^n)
int Longest_common_subsequence(string X,string Y,int n,int m)
{
    if(n==0 || m==0)
        return 0;
    
    if(X[n-1]==Y[m-1])
    {
        return (Longest_common_subsequence(X,Y,n-1,m-1) + 1);
    }
    else
    {
        return max(Longest_common_subsequence(X,Y,n-1,m),Longest_common_subsequence(X,Y,n,m-1));
    }

}

int main()
{
    string X,Y;
    cin>>X>>Y;
    int n=X.size();
    int m=Y.size();
    int ans=Longest_common_subsequence(X,Y,n,m);
    cout<<ans;
    return 0;
}
/*

*/