class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        int uniqueElement=0;
        int currElement=1;
        while(currElement<nums.size()){
            if(nums[currElement]!=nums[uniqueElement]){
                k++;
                swap(nums[uniqueElement+1],nums[currElement]);
                    uniqueElement++;
            }
            currElement++;
            
        }
        

        return k;
    
    }
};