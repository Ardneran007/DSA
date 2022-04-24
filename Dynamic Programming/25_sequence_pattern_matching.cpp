#include<bits/stdc++.h>
using namespace std;
//is string X a subsequence of string Y?
/*
X-AXY
Y-ADXCPY
if(lcs==x.length())
    return true

------------------------------------------
if quus was if X is substring of Y or Y is substring of X
then 
    if(lcs=min(x.length,y.length))
        return true

*/
int Longest_common_subsequence(string X,string Y,int n,int m)
{
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)//initialisation
                t[i][j]=0;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(X[i-1]==Y[j-1])//if last character are same
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
            
        }
    }

    return t[n][m];
}

bool subsequence_Pattern_matching(string X,string Y,int n,int m)
{
    int LCS_length=Longest_common_subsequence(X,Y,n,m);
    if(LCS_length==n)
        return true;
    else
        return false;
}
int main()
{
    string X,Y;
    cin>>X>>Y;
    int n=X.size();
    int m=Y.size();
    if(subsequence_Pattern_matching(X,Y,n,m))
        cout<<"YES";
    else    
        cout<<"NO";
    return 0;
}
/*

*/