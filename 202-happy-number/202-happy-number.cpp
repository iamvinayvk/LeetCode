class Solution {
public:
    int getNextSumSquare(int n){
        int ans=0;
        while(n){
            int temp=n%10;
            ans+=(temp*temp);
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
      int slow=n;
        int fast=n;
        do{
            slow=getNextSumSquare(slow);
            fast=getNextSumSquare(fast);
            fast=getNextSumSquare(fast);
        }while(slow!=fast);
        return slow==1?true:false;
    }
};