class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //Time Complexity O(nlogn)
        //Space Complexity O(logn)
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        //stored the value of first interval
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            //compared if the start value of next interval is less than or equal to previous interval then update the start and end 
            //it means they actually overlap 
            if(intervals[i][0]<=end){
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }
            //if they doesn't overlap then store the value and update the start and end 
            else{
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        //store the last interval 
        ans.push_back({start,end});
        return ans;
    }
};