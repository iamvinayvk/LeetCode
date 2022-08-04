class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0,n=nums.size();
        for(int i=0;i<n-count;i++){
            if(nums[i]==val){
                count++;
                for(int j=i+1;j<n;j++){
                    swap(nums[j-1],nums[j]);
                }
                i--;
            }
        }
        return nums.size()-count;
    }
};