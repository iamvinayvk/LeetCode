class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> ump;
        for(auto x:s){
            ump[x]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto x:ump){
            pq.push({x.second,x.first});
        }
        string ans="";
        while(pq.size()>0){
            int fre=pq.top().first;
            char ch=pq.top().second;
            for(int i=0;i<fre;i++)
                ans.push_back(ch);
            pq.pop();
        }
        return ans;
    }
};