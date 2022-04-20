class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int fromStart=1;
        int fromLast=1;
        for(int i=0;i<nums.size();i++){
            ans[i]*=fromStart;
            fromStart*=nums[i];
            ans[nums.size()-1-i]*=fromLast;
            fromLast*=nums[nums.size()-1-i];
        }
        return ans;
        
    }
};