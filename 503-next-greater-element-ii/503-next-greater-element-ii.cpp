class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=2*nums.size();
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            int flag=0;
            for(int j=i+1;j<n;j++){
                if(nums[(j)%nums.size()]>nums[i]){
                    ans[i]=nums[j%nums.size()];
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ans[i]=-1;
            }
        }
        return ans;
    }
};