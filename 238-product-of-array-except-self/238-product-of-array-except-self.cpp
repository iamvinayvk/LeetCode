class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct(nums.size()+1,1),suffixProduct(nums.size()+1,1);
        for(int i=0;i<nums.size();i++){
            prefixProduct[i+1]=prefixProduct[i]*nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            suffixProduct[i]=suffixProduct[i+1]*nums[i];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(prefixProduct[i]*suffixProduct[i+1]);
        }
        return ans;
        
    }
};