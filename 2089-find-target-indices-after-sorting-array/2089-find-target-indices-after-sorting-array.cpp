class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       int low=0,high=nums.size();
        vector<int> ans;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                high=mid;
                // cout<<high<<" :\n";
            }
            else {
                low=mid+1;
            }
        }
        
        for(int i=high;i<nums.size()&&nums[high]==target;i++){
            if(target==nums[i])
            ans.push_back(i);
        }
        return ans;
        
        
    }
};