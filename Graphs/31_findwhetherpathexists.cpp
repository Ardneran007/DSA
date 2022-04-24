#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    bool dfs(vector<vector<int>> &grid,int x,int y,vector<vector<bool>> &visited)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || visited[x][y] || grid[x][y]==0)
        {
            return false;
        }
        if(grid[x][y]==2){
            return true;
        }
        visited[x][y]=true;
        
        if( dfs(grid,x+1,y,visited) || dfs(grid,x,y-1,visited) || dfs(grid,x,y+1,visited) || dfs(grid,x-1,y,visited) ){
           return true;
        }
        else
            return false;
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
     
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1){
                    return dfs(grid,i,j,visited);
                }
            }
        }

        
    } 
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends