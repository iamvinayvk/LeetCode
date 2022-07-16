class Solution {
public:
    int mod=1e9+7;
    long long int sol(int m, int n, int maxMove, int startRow, int startColumn,vector<vector<vector<long long int>>>&dp)
    {
         if(startRow<0||startColumn<0||startRow>=m||startColumn>=n){
            return 1;
        }
        if(maxMove==0) return 0;
        
        if(dp[startRow][startColumn][maxMove]!=-1)
            return dp[startRow][startColumn][maxMove];
        
        return dp[startRow][startColumn][maxMove]=(((sol(m,n,maxMove-1,startRow-1,startColumn,dp)%mod)+ (sol(m,n,maxMove-1,startRow+1,startColumn,dp)%mod)%mod)+ ((sol(m,n,maxMove-1,startRow,startColumn-1,dp)%mod)+ (sol(m,n,maxMove-1,startRow,startColumn+1,dp))%mod)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       vector<vector<vector<long long int>>> dp(m+1,vector<vector<long long int>>(n+1,vector<long long int>(maxMove+1,-1)));
        
    sol(m,n,maxMove,startRow,startColumn,dp);
    // int ans=0;
    //     for(auto x:dp){
    //         for(auto y:x){
    //             // ans=max(y,ans);
    //             for(int z:y){
    //                 ans=max(z,ans);
    //             }
    //         }
    //     }
        return dp[startRow][startColumn][maxMove]==-1?0:dp[startRow][startColumn][maxMove];
        
    };
};