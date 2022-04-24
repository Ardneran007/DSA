#include<bits/stdc++.h>
using namespace std;
//find longest palidrome subsequence
int Longest_Repeting_subsequence(string X,string Y,int n,int m)
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
            if(X[i-1]==Y[j-1]  &&  i!=j)//if last character are same
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
//FORMULA
// LPS(string)=LCS(string,reverse(string));
int main()
{
    string a;
    cin>>a;
    int n=a.size();
    int LRS_length=Longest_Repeting_subsequence(a,a,n,n);
    cout<<"Longest Repeating Subsequence "<<LRS_length;
    return 0;
}
/*

*/