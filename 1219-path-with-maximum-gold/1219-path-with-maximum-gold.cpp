class Solution {
public:
    int findAns(vector<vector<int>>& grid,int n,int m,int r,int c,vector<vector<int>>& visited)     {
        if(r>=n||c>=m||r<0||c<0||visited[r][c]==1||grid[r][c]==0){
            return 0;
        }
        visited[r][c]=1;
        int down=findAns(grid,n,m,r+1,c,visited);
        int right=findAns(grid,n,m,r,c+1,visited);
        int up=findAns(grid,n,m,r-1,c,visited);
        int left=findAns(grid,n,m,r,c-1,visited);
        visited[r][c]=0;
        return grid[r][c]+max({down,right,up,left});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
                            vector<vector<int>> visited(n,vector<int>(m,0));

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0)
                {
                    ans=max(findAns(grid,n,m,i,j,visited),ans);    
                }
                
            }
        }
        return ans;
    }
};