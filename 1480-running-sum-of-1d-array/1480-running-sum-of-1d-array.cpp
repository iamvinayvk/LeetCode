class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int run=0;
        for(int i=0;i<nums.size();i++)
        {
            run+=nums[i];
            ans.push_back(run);
        }
        return ans;
    }
};