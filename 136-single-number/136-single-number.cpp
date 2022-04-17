class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(auto xx:nums){
            x^=xx;
        }
        return x;
        
    }
};