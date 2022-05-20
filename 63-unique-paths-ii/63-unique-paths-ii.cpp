class Solution {
public:
    int moves[2][2]={{0,1},{1,0}};
    int isValid(vector<vector<int>>& obstacleGrid,int i,int j,int n,int m){
        if(i<0||j<0||i>=m||j>=n||obstacleGrid[i][j]==1){
            return 0;
        }
        return 1;
    }
    int numberofPaths(vector<vector<int>>& obstacleGrid,int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i<0||j<0||i>=m||j>=n||obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right,down;
        if(dp[i+1][j]!=-1){
            down=dp[i+1][j];
        }
        else{
            down=numberofPaths(obstacleGrid,i+1,j,n,m,dp);
        }
         if(dp[i][j+1]!=-1){
            right=dp[i][j+1];
        }
        else{
            right=numberofPaths(obstacleGrid,i,j+1,n,m,dp);
        }
        // return numberofPaths(obstacleGrid,i+1,j,n,m)+numberofPaths(obstacleGrid,i,j+1,n,m);
        return dp[i][j]=down+right;
        

        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i=0,j=0,m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans=numberofPaths(obstacleGrid,i,j,n,m,dp);
        return ans;
    }
};