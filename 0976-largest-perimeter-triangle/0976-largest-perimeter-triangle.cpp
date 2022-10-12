class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-3;i>=0;i--){
           int s1=nums[i]+nums[i+1];
        int s2=nums[i+1]+nums[i+2];
        int s3=nums[i+2]+nums[i];
        if(s1>nums[i+2]&&s2>nums[i]&&s3>nums[i+1]){
            return nums[i]+nums[i+1]+nums[i+2];
        } 
        }
        
        return 0;
    }
};