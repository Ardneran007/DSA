#include <bits/stdc++.h>
using namespace std;
bool visited[100][100];
int N,M;
/*
Cells-Nodes
Side-Edges
Sides + Corner =Edges
*/
bool isValid(int x,int y)
{
    if(x<1 || y<1 || x>N || y>M)//N*M
        return false;
    if(visited[x][y]==true)
        return false;
    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x, int y)
{
    visited[x][y]=true;
    cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i],y+dy[i]))
            dfs(x+dx[i],y+dy[i]);
    }

    // if(isValid(x-1,y))
    //     dfs(x-1,y);//up

    // if(isValid(x,y+1))
    //     dfs(x,y+1);//right

    // if(isValid(x+1,y))
    //     dfs(x+1,y);//down

    // if(isValid(x,y-1))
    //     dfs(x,y-1);//left
}

int main() {
    // int N,M;
    cin>>N>>M;
    dfs(1,1);
    return 0;
}   