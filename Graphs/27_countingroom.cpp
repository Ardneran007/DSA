#include <bits/stdc++.h>
using namespace std;
bool visited[1002][1002];
int N,M;
char A[1002][1002];
/*
Cells-Nodes
Side-Edges
Sides + Corner =Edges
*/
bool isValid(int x,int y)
{
    if(x<1 || y<1 || x>N || y>M)//N*M
        return false;
    if(visited[x][y]==true || A[x][y]=='#')//we have to move from . to .and not from #
        return false;
    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x, int y)
{
    visited[x][y]=true;
    // cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i],y+dy[i]))
            dfs(x+dx[i],y+dy[i]);
    }

}

int main() {
    // int N,M;
    cin>>N>>M;
    // int A[N][M];
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin>>A[i][j];
        }
    }

    int count=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(visited[i][j]==false && A[i][j]=='.')
            {
                dfs(i,j);
                count++;
            }
        }
    }

    cout<<count;
    return 0;
}   
/*
6 6
0 0 1 0 1 1
0 1 1 0 0 1
0 1 0 0 0 0
1 0 1 1 0 0
0 0 0 1 0 0 
0 1 1 0 1 1


*/