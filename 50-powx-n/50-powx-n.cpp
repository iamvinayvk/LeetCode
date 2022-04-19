class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        // if(n<0){
        //     n = -(n+1);
        //     x = (1/x)*(1/x);
        // }
         if(n<0) return 1/x * myPow(1/x, -(n+1));
        double xn2=myPow(x,n/2);
        xn2*=xn2;
        if(n%2==1)
        {
            xn2*=x;
        }
        return xn2;
    }
};