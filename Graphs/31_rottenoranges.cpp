#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
         int tot=0,cnt=0,days=0;
    if(grid.empty())
        return 0;
    
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int> >rotten;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]!=0)
                tot++;
            if(grid[i][j]==2)
                rotten.push({i,j});
        }
    }
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};

    while(!rotten.empty())
    {
        int k=rotten.size();
        cnt+=k;
        while(k--)
        {
            int x=rotten.front().first;
            int y=rotten.front().second;
            rotten.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x + dx[i];
                int ny=y + dy[i];

                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1)
                    continue;
                
                grid[nx][ny]=2;
                rotten.push({nx,ny});
            }
        }
        if(!rotten.empty())
            days++;
    }
    return (tot==cnt) ? days : -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends