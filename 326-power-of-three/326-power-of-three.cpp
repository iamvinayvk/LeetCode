class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
       for(long long int i=3;i<=n;i*=3)
       {
           if(i==n)
               return true;
       }
        return false;
    }
};