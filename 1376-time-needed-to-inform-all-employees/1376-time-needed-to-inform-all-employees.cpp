class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n+1);
        for(int i=0;i<manager.size();i++){
            int x=manager[i];
            int y=i;
            if(x!=-1)
            graph[x].push_back(y);
        }
        queue<int> q;
        q.push(headID);
        int ans=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans=max(ans,informTime[curr]);
            for(auto child:graph[curr]){
                informTime[child]+=informTime[curr];
                q.push(child);
            }
        }
        
        
        return ans;
    }
};