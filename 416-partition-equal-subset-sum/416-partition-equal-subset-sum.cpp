class Solution {
public:
    bool ans(vector<int>& nums,int i,int n,int sum,int total_sum,vector<vector<int>>& dp){
        if(i>=n)
            return false;
        if(sum==total_sum)
            return true;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        return dp[i][sum]=ans(nums,i+1,n,sum+nums[i],total_sum-nums[i],dp)||ans(nums,i+1,n,sum,total_sum,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0,total_sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
        }
                vector<vector<int>> dp(n+1,vector<int>(total_sum+1,-1));

        return ans(nums,0,n,sum,total_sum,dp);
    }
};