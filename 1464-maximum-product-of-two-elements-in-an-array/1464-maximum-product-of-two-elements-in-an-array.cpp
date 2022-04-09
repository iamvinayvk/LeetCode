class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        ans=(nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);
        return ans;
    }
};