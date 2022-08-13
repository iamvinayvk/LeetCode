class Solution {
public:
    bool isPerfectSquare(int num) {
        int n=sqrt(num);
        cout<<n<<"\n";
        if(num-n*n<0.00001){
            return true;
        }
        return false;
    }
};