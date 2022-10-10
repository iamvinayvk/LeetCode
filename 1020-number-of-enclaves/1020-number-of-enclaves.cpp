class Solution {
public:
    void replaceCell(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        replaceCell(grid,i+1,j);
        replaceCell(grid,i-1,j);
        replaceCell(grid,i,j+1);
        replaceCell(grid,i,j-1);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<grid.size();i++){
            int val=grid[i][0];
            if(val==1){
                replaceCell(grid,i,0);
            }
        }
        for(int i=0;i<grid.size();i++){
            int val=grid[i][m-1];
            if(val==1){
                replaceCell(grid,i,m-1);
            }
        }
        for(int i=0;i<m;i++){
            int val=grid[0][i];
            if(val==1){
                replaceCell(grid,0,i);
            }
        }
        for(int i=0;i<m;i++){
            int val=grid[n-1][i];
            if(val==1){
                replaceCell(grid,n-1,i);
            }
        }
        for(auto x:grid){
            for(auto y:x)
            ans+=y;
        }
        return ans;
    }
};