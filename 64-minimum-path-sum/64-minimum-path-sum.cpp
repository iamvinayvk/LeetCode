class Solution {
public:
    int findAns(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i>=n||j>=m)
            return 1e6;
        if(i==n-1&&j==m-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        long long int down=INT_MAX,right=INT_MAX;
        // if(i<n)
        down=grid[i][j]+findAns(grid,i+1,j,n,m,dp);
        // if(j<m)
        right=grid[i][j]+findAns(grid,i,j+1,n,m,dp);
        return dp[i][j]=min(down,right);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int i=0,j=0;
        vector<vector<int>> dp(n+1,vector<int>(m,-1));
        int ans=findAns(grid,i,j,n,m,dp);
        // cout<<"--------------\n";
        return ans;
    }
};