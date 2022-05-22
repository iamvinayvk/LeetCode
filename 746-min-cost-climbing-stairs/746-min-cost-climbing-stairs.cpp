class Solution {
public:
    int minCost(vector<int>& cost,int n,vector<int>& dp){
        //base case
        if(n<=1){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int oneStep=minCost(cost,n-1,dp)+cost[n-1];
        int twoStep=INT_MAX;
        if(n>1){
            twoStep=minCost(cost,n-2,dp)+cost[n-2];
        }
        return dp[n]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        int res=minCost(cost,n,dp);
        return res;
    }
};