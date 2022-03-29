class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+5,vector<int>(n+5));
        return uniquePathHelper(m-1,n-1,dp);
    }
    int uniquePathHelper(int m,int n,vector<vector<int>>& dp){
        
        if(m<0||n<0)
            return 0;
        if(m==0||n==0)
            return 1;
        if(dp[m][n]!=0)
            return dp[m][n];
        
        return dp[m][n]=uniquePathHelper(m-1,n,dp)+uniquePathHelper(m,n-1,dp);
    }
};