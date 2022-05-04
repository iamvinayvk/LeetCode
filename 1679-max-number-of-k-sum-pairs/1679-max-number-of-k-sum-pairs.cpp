class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //Two Sum Approach 
        unordered_map<int,int> fre;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int secondNumber=k-nums[i];
            if(fre[secondNumber]>0){
                ans++;
                fre[secondNumber]--;
            }
            else{
                fre[nums[i]]++;
            }
        }
        return ans;
    }
};