class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves=0;
        // int mini=*minimum_element(nums.begin(),nums.end());
        int mini=INT_MAX;
        for(auto x:nums)
            mini=min(x,mini);
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            moves+=(nums[i]-mini);
        }
        return moves;
        
        
    }
};