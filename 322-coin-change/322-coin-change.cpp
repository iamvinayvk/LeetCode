class Solution {
public:
    int numberofCoins(vector<int>& coins,int amount,int index,vector<vector<int>>& dp){
        //Base Case
        if(index==0){
            if(amount%coins[index]==0){
                return amount/coins[index];
            }
            else{
                return 1e9;
            }
        }
        if(amount==0)
            return 0;
        if(amount<0){
            return 1e9;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        //recurrence
        int notTake=numberofCoins(coins,amount,index-1,dp);
        int take=INT_MAX;
        if(coins[index]<=amount)
        take=1+min(numberofCoins(coins,amount-coins[index],index,dp),take);
        // if(coins)
        return dp[index][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int res=0;
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        res=numberofCoins(coins,amount,n-1,dp);
        if(res==1e9)
            return -1;
        return res;
    }
};