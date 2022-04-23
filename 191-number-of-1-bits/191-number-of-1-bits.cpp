class Solution {
public:
    int hammingWeight(uint32_t n) {
        int val=0;
        while(n>0){
            n=n&(n-1);
            
            val++;
        }
        return val;
    }
};