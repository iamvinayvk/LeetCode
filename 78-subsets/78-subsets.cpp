class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        sub(nums,0,temp,ans);
        return ans;
    }
    void sub(vector<int>& nums,int j,vector<int>& temp,vector<vector<int>>& ans){
        ans.push_back(temp);
        for(int i=j;i<nums.size();i++){
            temp.push_back(nums[i]);
            sub(nums,i+1,temp,ans);
            temp.pop_back();
        }
    }
};