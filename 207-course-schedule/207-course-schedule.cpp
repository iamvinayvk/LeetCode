class Solution {
public:
    bool dfs(int v,vector<int>& visited,vector<vector<int>>& graph,vector<int>& path){
        
        if(visited[v]==0){
            visited[v]=1;
            path[v]=1;
            for(auto child:graph[v]){
            
            if(!visited[child]){
                if(dfs(child,visited,graph,path)){
                    return true;
                }
            }
                else if(path[child]){
                    return true;
                }
            
        }
        }
        
    path[v]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses),path(numCourses);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool isCycle=dfs(i,visited,graph,path);
                if(isCycle)
                    return false;
            }
        }
        return true;
    }
};