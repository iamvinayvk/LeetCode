class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto x:arr)
            mp[x]++;
        int size=mp[arr[0]];
        for(auto x:mp){
            for(int i=0;i<arr.size();i++){
                if(x.first!=arr[i]&&x.second==mp[arr[i]])
                    return false;
            }
        }
        return true;
    }
};