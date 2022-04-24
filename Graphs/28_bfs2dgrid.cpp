#include <bits/stdc++.h>
using namespace std;
int visited[1001][1001];
int dist[1001][1001];
int N,M;

bool isValid(int x,int y)
{
    if(x<1 || y<1 || x>N || y>M)//N*M
        return false;
    if(visited[x][y]==1)
        return false;
    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void bfs(int srcX,int srcY)
{
    queue<pair<int,int> > q;
    q.push({srcX,srcY});
    visited[srcX][srcY]=1;
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

    cout<<" dist \n";
     for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main() {
    int sx,sy;
    cout<<"Enter m and N\n";
    cin>>N>>M;
    cout<<"Enter source\n";
    cin>>sx>>sy;

    bfs(sx,sy);
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