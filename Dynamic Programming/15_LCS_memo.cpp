#include<bits/stdc++.h>
using namespace std;
//first check constraints of n and m 
// there is two way for matrix one globally and other pasiing it in function 
//suppose constraints -> n and m <=1000
int  static t[1001][1001];//it si good to use static
//time->theta(mn)
int Longest_common_subsequence(string X,string Y,int n,int m)
{
    if(n==0 || m==0)
        return 0;
    
    if(t[n][m]!=-1)
        return t[n][m];
    if(X[n-1]==Y[m-1])
    {
        return t[n][m]=(Longest_common_subsequence(X,Y,n-1,m-1) + 1);
    }
    else
    {
        return t[n][m]=max(Longest_common_subsequence(X,Y,n-1,m),Longest_common_subsequence(X,Y,n,m-1));
    }

}

int main()
{
    memset(t,-1,sizeof(t));
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