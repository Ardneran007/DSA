#include<bits/stdc++.h>
using namespace std;
/*
here common substring must be contigous 
 make length 0 when discontinous->variation

*/
int Longest_common_substring(string X,string Y,int n,int m)
{
    int ans=0;
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
                ans=max(ans,t[i][j]);//imp checking here the max and storing it
            }
            else
            {
                t[i][j]=0; 
            }
            
        }
    }

    return ans;//here we need to return max in all matrix
}

int main()
{
    string X,Y;
    cin>>X>>Y;
    int n=X.size();
    int m=Y.size();
    int ans=Longest_common_substring(X,Y,n,m);
    cout<<ans;
    return 0;
}
/*

*/