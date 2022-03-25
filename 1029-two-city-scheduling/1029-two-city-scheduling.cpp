class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //Time Complexity O(nlogn)
        //Space Complexity O(n)
        vector<pair<int,int>> diff(costs.size());
        for(int i=0;i<costs.size();i++){
            diff[i].first=costs[i][1]-costs[i][0];
            diff[i].second=i;
        }
        sort(diff.begin(),diff.end());
        int ans=0;
        int i=0,j=costs.size()-1;
        while(i<j){
            
                ans+=costs[diff[i].second][1]+costs[diff[j].second][0];
            i++;
            j--;
            
        }
        return ans;
    }
};