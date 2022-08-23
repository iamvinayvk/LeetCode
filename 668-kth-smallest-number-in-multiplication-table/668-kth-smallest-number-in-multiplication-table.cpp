class Solution {
public:
    bool enough(int mid,int m,int n,int k){
        int count=0;
        for(int i=1;i<=m;i++){
            count+=min(mid/i,n);
        }
        return count>=k;
    }
    int findKthNumber(int m, int n, int k) {
    
        int small=1,large=m*n;
        while(small<large){
            int mid=small+(large-small)/2;
           if(enough(mid,m,n,k)){
               large=mid;
           }
            else{
                small=mid+1;
            }
        }
        return large;
    }
    
};