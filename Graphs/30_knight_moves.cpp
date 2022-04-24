#include <bits/stdc++.h>
using namespace std;
int visited[1001][1001];
int dist[1001][1001];
int N;
//Minimum no of moves for a knight 
bool isValid(int x,int y)
{
    if(x<1 || y<1 || x>8 || y>8)//N*M
        return false;
    if(visited[x][y]==1)
        return false;
    return true;
}

int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

int bfs(int srcX,int srcY,int tarX,int tarY)
{
    visited[srcX][srcY]=1;
    dist[srcX][srcY]=0;

    queue<pair<int,int>> q;
    q.push({srcX,srcY});

    if(srcX==tarX && srcY==tarY)
        return 0;

    while(!q.empty())
    {
        int currX=q.front().first;
        int currY=q.front().second;
        q.pop();

        for(int i=0;i<8;i++)
        {
            if(isValid(currX + dx[i],currY + dy[i]))
            {
                int x=currX + dx[i];
                int y=currY + dy[i];

                dist[x][y]=dist[currX][currY] + 1;
                visited[x][y]=1;
                q.push({x,y});

                if(x==tarX && y==tarY)
                    return dist[x][y];
            }
        }
    }
}


int main() {
    int sx,sy;
    int tx,ty;
    cin>>sx>>sy>>tx>>ty;
    cout<<bfs(sx,sy,tx,ty);
    return 0;
}   
/*



*/