#include<bits/stdc++.h>
using namespace std;


vector<int> subset_sum(int A[],int range,int n)
{
    bool t[n+1][range+1];
    vector<int> temp;// to store last row
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<range+1;j++)
        {
            if(i==0)
                t[i][j]=false;
            if(j==0)
                t[i][j]=true;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<range+1;j++)
        {
            if(A[i-1] <= j)
            {
                t[i][j]= (t[i-1][j-A[i-1]]) || (t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }

    for(int j=0;j<=range/2;j++)//
    {
        if(t[n][j]==true)
        {
            temp.push_back(j);
        }
    }

    return temp;
}


int main()
{
    int n,range=0;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    
    for(int i=0;i<n;i++)
        range+=A[i];

    vector<int> temp;
    temp=subset_sum(A,range,n);
    //s2 - s1 min
    //range -2*s1 min
    //s1 max
    int ans=range-2*(temp[temp.size()-1]);//s1 will be max
    cout<<"Minimum diff->"<<ans;
    
    return 0;
}