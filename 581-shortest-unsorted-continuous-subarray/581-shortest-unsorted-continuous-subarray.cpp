class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int startIndex=nums.size();
        int lastIndex=0;
        vector<int> newNums=nums;
        sort(newNums.begin(),newNums.end());
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" | "<<nums[i]<<"\n";
            if(newNums[i]!=nums[i]){
                startIndex=min(startIndex,i);
                lastIndex=max(lastIndex,i);
            }
        }
        cout<<lastIndex<<" "<<startIndex<<"\n";
        if(lastIndex-startIndex<0){
            return 0;
        }
        return lastIndex-startIndex+1;
    }
};