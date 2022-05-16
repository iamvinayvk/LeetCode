class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pointerZero=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0&&pointerZero==-1){
                pointerZero=i;
            }
            else if(pointerZero!=-1&&nums[i]!=0){
                          swap(nums[pointerZero],nums[i]);
                // pointerZero++;
                while(pointerZero<nums.size()&&nums[pointerZero]!=0){
                    pointerZero++;
                }
                // cout<<pointerZero<<"\n";
            }
        }
        
    }
};