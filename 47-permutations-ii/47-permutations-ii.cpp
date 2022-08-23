class Solution {
public:
    void solve(vector<int>& nums,set<vector<int>>& s,vector<int> temp){
        if(temp.size()==nums.size()){
            s.insert(temp);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=11){
                int j=nums[i];
                nums[i]=11;
                temp.push_back(j);
                solve(nums,s,temp);
                nums[i]=j;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        solve(nums,s,{});
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};