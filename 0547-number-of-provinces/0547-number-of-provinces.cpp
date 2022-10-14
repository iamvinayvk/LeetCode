class Solution {
public:
    void dfs(vector<vector<int>>& graph,int i,vector<int>& visited){
        visited[i]=1;
        for(auto x:graph[i]){
            if(!visited[x]){
                dfs(graph,x,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> graph(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    graph[i+1].push_back(j+1);
                }
            }
        }
        int cc=0;
        vector<int> visited(n+1);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                // cout<<i<<" -\n";
                dfs(graph,i,visited);
                cc++;
            }
        }
        return cc;
    }
};