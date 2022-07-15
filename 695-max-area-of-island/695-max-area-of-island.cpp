class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int i,int j,int n,int m){
         if(i<0||j<0||i>=m||j>=n||grid[i][j]==0)
            return false;
        return true;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int& ans){
       
        ans+=1;
        grid[i][j]=0;
        if(isValid(grid,i+1,j,n,m))
        {
            dfs(grid,i+1,j,n,m,ans);
            // cout<<"i+1 "<<i+1<<" j "<<j<<"\n";
        }
        
        if(isValid(grid,i-1,j,n,m))
        {
                    dfs(grid,i-1,j,n,m,ans);
                        // cout<<"i-1 "<<i-1<<" j "<<j<<"\n";


        }
        if(isValid(grid,i,j-1,n,m))
        {
                    dfs(grid,i,j-1,n,m,ans);
                        // cout<<"i "<<i<<" j-1 "<<j-1<<"\n";


        }
        if(isValid(grid,i,j+1,n,m))
        {
                   dfs(grid,i,j+1,n,m,ans);
                        // cout<<"i "<<i<<" j+1 "<<j+1<<"\n";

 
        }
        // grid[i][j]=0;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int ans=0;
                    dfs(grid,i,j,n,m,ans);
                    result=max(ans,result);
                }
            }
        }
        return result;
    }
};