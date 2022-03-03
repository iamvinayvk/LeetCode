class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int count=0;
        int n=nums.size();
        if(n<3){
            return ans;
        }
        for(int i=0;i<n-2;i++){
            if((nums[i+2]-nums[i+1])==(nums[i+1]-nums[i]))
            {
                count++;
            }
            else
            {

                ans=ans+count*(count+1)/2;
                count=0;
            }
            
        }
        ans=ans+count*(count+1)/2;
        return ans;
    }
};