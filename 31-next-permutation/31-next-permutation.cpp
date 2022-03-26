class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int compareValue=nums[nums.size()-1];
        int i;
      for(i=nums.size()-2;i>=0;i--){
          if(compareValue>nums[i]){
              compareValue=nums[i];
              break;
          }
          compareValue=nums[i];
      }  
        int justGreater=INT_MAX;
        int j;
        int index=nums.size();
        for(j=i+1;j<nums.size();j++){
            if(nums[j]<=justGreater&&justGreater>=compareValue&&nums[j]>compareValue){
                cout<<"comapre: "<<compareValue<<" "<<nums[j]<<" "<<justGreater<<"\n";
                justGreater=nums[j];
                index=j;
            }
        }
        cout<<i<<" ) "<<j<<" "<<index<<"\n";
        if(index<nums.size()&&i>=0){
            swap(nums[i],nums[index]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};