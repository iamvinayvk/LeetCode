class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int startSum=0;
        int lastSum=1e9+1;
        int ans=0;
        while(startSum<=lastSum){
            int midSum = startSum+(lastSum-startSum)/2;
            if(isPossible(midSum,m,nums)){
                ans=midSum;
                lastSum=midSum-1;
            }
            else{
                startSum=midSum+1;
            }
            
        }
        return ans;
    }
    bool isPossible(int midSum,int m,vector<int>& nums){
        int subArrays=1;
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>midSum||subArrays>m)
                return false;
            if(currSum+nums[i]<=midSum){
                currSum+=nums[i];
            }
            else{
                currSum=nums[i];
                subArrays++;
            }
        }
        return (subArrays<=m);
    }
};