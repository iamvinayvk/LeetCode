// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isSafe(int i,int j,int n,int m){
        return (i>=0&&j>=0&&i<n&&j<m);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,int> curr=q.front();
                q.pop();
                int X=curr.first;
                int Y=curr.second;
                if(isSafe(X+1,Y,grid.size(),grid[0].size())&&grid[X+1][Y]==1){
                    q.push({X+1,Y});
                    grid[X+1][Y]=2;
                }
                if(isSafe(X-1,Y,grid.size(),grid[0].size())&&grid[X-1][Y]==1){
                    q.push({X-1,Y});
                    grid[X-1][Y]=2;
                }
                if(isSafe(X,Y+1,grid.size(),grid[0].size())&&grid[X][Y+1]==1){
                    q.push({X,Y+1});
                    grid[X][Y+1]=2;
                }
                if(isSafe(X,Y-1,grid.size(),grid[0].size())&&grid[X][Y-1]==1){
                    q.push({X,Y-1});
                    grid[X][Y-1]=2;
                }
            
                
            }
            ans++;
        }
        for(auto x:grid){
            for(auto y:x){
                if(y==1)
                return -1;
            }
        }
        return ans-1;
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