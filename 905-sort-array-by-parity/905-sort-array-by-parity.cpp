class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            if(nums[left]%2){
                while(left<right&&nums[right]%2){
                    right--;
                }
                swap(nums[left],nums[right]);
            }
            left++;
        }
        return nums;
    }
};