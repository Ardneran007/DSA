#include <bits/stdc++.h>
using namespace std;
int visited[1001][1001];
int dist[1001][1001];
char A[1001][1001];
int N;
//junglerun hackerearth
bool isValid(int x,int y)
{
    if(x<1 || y<1 || x>N || y>N)//N*M
        return false;
    if(visited[x][y]==1 || A[x][y]=='T')
        return false;
    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void bfs(int srcX,int srcY)
{
    queue<pair<int,int> > q;
    visited[srcX][srcY]=1;
    q.push({srcX,srcY});
    dist[srcX][srcY]=0;

    while(!q.empty())
    {
        int currX=q.front().first;
        int currY=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            if(isValid(currX + dx[i],currY + dy[i]))
            {
                int newX=currX + dx[i];
                int newY=currY + dy[i];

                q.push({newX,newY});
                visited[newX][newY]=1;
                dist[newX][newY]=dist[currX][currY]+1;
            }
        }
    }

}


int main() {
    int srcX,srcY,endX,endY;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>A[i][j];
            if(A[i][j]=='S')
            {
                srcX=i;
                srcY=j;
            }
            if(A[i][j]=='E')
            {
                endX=i;
                endY=j;
            }
        }
    }
    bfs(srcX,srcY);
    cout<<dist[endX][endY];
    return 0;
}   
/*
5
S P P P P
T P T P P
T P P P P
P T E T T
P T P T T



*/