class Solution {
public:
    int ans(vector<vector<int>>& matrix,int i,int j,int n,vector<vector<int>>& dp){
        if(j==n||i==n||j<0)
            return 0;
        int left=INT_MAX,curr=INT_MAX,right=INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j-1>=0)
            left=matrix[i][j]+ans(matrix,i+1,j-1,n,dp);
        if(j+1<n)
            right=matrix[i][j]+ans(matrix,i+1,j+1,n,dp);
        curr=matrix[i][j]+ans(matrix,i+1,j,n,dp);
        return dp[i][j]=min({left,right,curr});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res=INT_MAX;
        int n=matrix.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            res=min(res,ans(matrix,0,i,n,dp));
        }
        return res;
    }
};