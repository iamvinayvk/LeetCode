class Solution {
public:
    int ans(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
        
        
        if(j==triangle.size())
            return 0;
        int curr=1e6,curr_1=1e6;
        // cout<<j<<" "<<i<<" \n";
        // dp.resize(triangle.size(),vector<int>(triangle[j].size()));
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i<j+1)
            curr=triangle[j][i]+ans(triangle,i,j+1,dp);
        if(i+1<j+1)
            curr_1=triangle[j][i+1]+ans(triangle,i+1,j+1,dp);
        return dp[i][j]=min(curr,curr_1);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return ans(triangle,0,0,dp);
    }
};