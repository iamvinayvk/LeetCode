class Solution {
public:
     int Bsearch(int i,int j,vector<int> &nums,int target){
        while(i<=j){
            int mid=i+(j-i)/2;
            cout<<"mid: "<<mid<<"\n";
            if(nums[mid]==target) return mid;
            if(nums[mid]>target){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        
        while(i<j){
            int mid=i+(j-i)/2;
            if(nums[mid]>=nums[0]){
                i=mid+1;
            }else{
                j=mid;
            }
        }
        int pivot =i;
        cout<<pivot<<"\n";
        if(nums[i]>nums[0]){
            pivot=0;
        }
        int ans1=Bsearch(0,pivot-1,nums,target);
        int ans2=Bsearch(pivot,nums.size()-1,nums,target);
        
        return max(ans1,ans2);
    }
};