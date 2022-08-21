class Solution {
public:
    bool isPossible(vector<int>& nums,int m,int midSum){
        int sa=1;
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            if(currSum>midSum||sa>m)
                return false;
            else if(currSum+nums[i]<=midSum){
                currSum+=nums[i];
            }
            else{
                currSum=nums[i];
                sa++;
            }
        }
        return sa<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int startSum=0,lastSum=1e9;
        while(startSum<lastSum){
            int midSum=startSum+(lastSum-startSum)/2;
            
            if(isPossible(nums,m,midSum)){
                // cout<<"lastSum:"<<midSum<<"\n";
                lastSum=midSum;
            }
            else{
                startSum=midSum+1;
            }
        }
        return lastSum;
    }
};