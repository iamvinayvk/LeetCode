class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        int count=1;
        map<int,int> mp;
        if(nums.size()==0)
            return 0;
        // sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            
        }
        int prev=INT_MIN;
        for(auto x:mp){
            if(prev!=INT_MIN){
                if(x.first==prev+1){
                    count++;
                }
                else{
                    ans=max(ans,count);
                    count=1;
            
                }
            }
                prev=x.first;
            
        }
        ans=max(ans,count);
        return ans;
        
    }
};