class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        int count=1;
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i-1]+1==nums[i]){
                                // cout<<nums[i-1]<<" "<<nums[i]<<"\n";

                count++;
            }
            else{
                // cout<<nums[i-1]<<" "<<nums[i]<<"\n";
                ans=max(ans,count);
                count=1;
            }
            }
            
        }
        ans=max(ans,count);
        return ans;
        
    }
};