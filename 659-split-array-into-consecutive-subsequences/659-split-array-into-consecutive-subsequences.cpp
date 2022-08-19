class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> available,vacancy;
        for(auto x:nums){
            available[x]++;
        }
        for(auto x:nums){
            if(!available[x])
                continue;
            available[x]--;
            if(vacancy[x-1]>0){
                vacancy[x-1]--;
                vacancy[x]++;
            }
            else if(available[x+1]&&available[x+2]){
                available[x+1]--;
                available[x+2]--;
                vacancy[x+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
};