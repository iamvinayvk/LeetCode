class Solution {
public:
    void findans(vector<int>& nums,int i,int j,int n,vector<int> temp,vector<int>& ans,vector<int>& dp){
        if(i==n){
            if(temp.size()>ans.size())
                ans=temp;
            return ;
        }
    
        if(nums[i]%j==0){
            if(dp[i]<(int)temp.size()){
                   dp[i]=temp.size();
                  temp.push_back(nums[i]);
         
            findans(nums,i+1,nums[i],n,temp,ans,dp);
            temp.pop_back(); 
            }
         
        }
        findans(nums,i+1,j,n,temp,ans,dp);
        return ;
        
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        
        int n=nums.size();
        vector<int> temp,ans;
        vector<int> dp(n+1,-1);
        sort(nums.begin(),nums.end());
        findans(nums,0,1,n,temp,ans,dp);
        return ans;
        
    }
};