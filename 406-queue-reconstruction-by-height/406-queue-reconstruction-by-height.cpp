class Solution {
public:
    static bool comp(vector<int>& p1,vector<int>& p2){
        if(p1[0]==p2[0])
        {
            return p1[1]<p2[1];
        }
        return p1[0]>p2[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);
        vector<vector<int>> ans;
        for(int i=0;i<people.size();i++){
            ans.insert(ans.begin()+people[i][1],people[i]);
        }
        return ans;
    }
};