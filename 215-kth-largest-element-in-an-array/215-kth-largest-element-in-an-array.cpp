class Solution {
public:
   int partition(vector<int>& nums,int lo,int hi){
       int pivot=nums[hi];
       int i=lo;
       for(int j=lo;j<=hi;j++){
           if(nums[j]<=pivot){
               swap(nums[j],nums[i++]);
           }
       }
       // swap(nums[i-1],nums[hi]);
       // cout<<i<<" "<<pivot<<"\n";
       // for(auto x:nums){
       //     cout<<x<<" ";
       // }
       // cout<<"\n";
       return i-1;
   }
    int findKthLargest(vector<int>& nums, int k) {
        int lo=0,hi=nums.size()-1;
        k=nums.size()-k;
        // cout<<"k: "<<k<<"\n";
        while(lo<=hi){
            // cout<<"low: "<<lo<<" high: "<<hi<<"\n";
            int pi=partition(nums,lo,hi);
            if(pi>k){
                hi=pi-1;
            }
            else if(pi<k){
                lo=pi+1;
            }
            else{
                return nums[pi];
            }
        }
        return 0;
        
    }
};