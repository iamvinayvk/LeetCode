class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        if(nums.size()<3)
            return 0;
        for(int i=0;i<nums.size();i++){
            int k=i+2;
            for(int j=i+1;j<nums.size();j++){
                while(k<nums.size()&&nums[i]+nums[j]>nums[k])
                    k++;
                if(k>=j+1)
                count+=(k-j-1);
            }
        }
        return count;
    }
};