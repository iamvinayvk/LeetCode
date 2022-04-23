class Solution {
public:
    int hammingWeight(uint32_t n) {
        int val=0;
        while(n>0){
            val+=n&1;
            
            n>>=1;
        }
        return val;
    }
};