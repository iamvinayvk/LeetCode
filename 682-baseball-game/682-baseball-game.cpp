class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> nums;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+"){
                int ans=0;
                ans=nums[nums.size()-1]+nums[nums.size()-2];
                // nums.clear();
                nums.push_back(ans);
            }
            else if(ops[i]=="C"){
                nums.erase(nums.end()-1);
            }
            else if(ops[i]=="D"){
                int ans=0;
                int val=nums[nums.size()-1];
                ans=2*val;
                // nums.erase(nums.end()-1);
                nums.push_back(ans);
            }
            else{
                nums.push_back(stoi(ops[i]));
            }
            // for(auto x: nums){
            //     cout<<x<<" ";
            // }
            // cout<<"\n";
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
        }
        return ans;
    }
};