class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(ans,0,nums.size()-1,nums);
        return ans;
    }
    void perm(vector<vector<int>>& ans,int l,int r,vector<int>& nums){
        if(l==r)
        {
            ans.push_back(nums);
        }
        else{
            for(int i=l;i<=r;i++){
                swap(nums[l],nums[i]);
                perm(ans,l+1,r,nums);
                swap(nums[l],nums[i]);
                
                }
        }
    }
};