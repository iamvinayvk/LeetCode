class Solution {
public:
    bool isBipartitePossible(vector<vector<int>>& graph,vector<int>& color,int v,int curr_color){
        color[v]=curr_color;
        for(auto child:graph[v]){
            if(color[child]==0){
                if(!isBipartitePossible(graph,color,child,(curr_color%2)+1))
                {
                return false;
                }
            }
            if(color[child]==color[v])
                return false;
        }
        return true;
                   
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> color(n+1);
        for(int i=1;i<=n;i++){
            int curr_color=1;
            if(color[i]==0&&!isBipartitePossible(graph,color,i,curr_color))
            {
                return false;
            }
        }
        return true;
    }
};