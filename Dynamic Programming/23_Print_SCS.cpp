#include<bits/stdc++.h>
using namespace std;
//GOOD QUUS
string Print_SCS(string X,string Y,int n,int m)
{
    //populating the matrix
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

    //--------------------------------------------------------------------
    //Tracing the path 
    string ans="";
    int i=n,j=m;//start from last block
    while(i>0 && j>0)
    {
        if(X[i-1]==Y[j-1])//if last character are same
        {
            ans.push_back(X[i-1]);
            i--;//imp
            j--;//imp
        }
        else
        {
            if(t[i-1][j] > t[i][j-1])
            {
                ans.push_back(X[i-1]);//
                i--;
            }
            else
            {
                ans.push_back(Y[j-1]);//
                j--;
            }
        }
    }

    while(i>0)//
    {
        ans.push_back(X[i-1]);
        i--;
    }

    while(j>0)//
    {
        ans.push_back(Y[j-1]);
        j--;
    }
    reverse(ans.begin(),ans.end());//need to reverse
    return ans;
}

int main()
{
    string X,Y;
    cin>>X>>Y;
    int n=X.size();
    int m=Y.size();
    string ans=Print_SCS(X,Y,n,m);
    cout<<ans;
    return 0;
}
/*

*/