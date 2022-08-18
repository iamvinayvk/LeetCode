class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto x: arr){
            mp[x]++;
        }
        priority_queue<pair<int,int>> pq;
        int size=0;
            int ans=0;
        for(auto x: mp){
            pq.push({x.second,x.first});
            size+=x.second;
            if(2*size>arr.size()){
                size-=pq.top().first;
                ans++;
                pq.pop();
                
            }
        }
        return ans;
        
        
    }
};