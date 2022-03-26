class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0,mid=0,last=nums.size()-1;
        while(mid<=last){
            if(nums[mid]==2){
                swap(nums[mid],nums[last--]);
            
            }
            else if(nums[mid]==0){
                swap(nums[mid],nums[start++]);
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
        }
    }
};