class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited){
        if(i<0||j<0||i>=grid.size()||j>=grid.size()||grid[i][j]==1||visited[i][j]==1){
            return false;
        }
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> visited(grid.size(),vector<int>(grid.size(),0));
        vector<vector<int>> distance(grid.size(),vector<int>(grid.size(),1e9));
        int dx[8]={0,0,1,-1,1,-1,1,-1};
        int dy[8]={1,-1,0,0,1,-1,-1,1};
        // visited[0][0]=1;
        distance[0][0]=1;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            visited[curr.first][curr.second]=1;
            for(int i=0;i<8;i++){
                int newX=curr.first+dx[i];
                int newY=curr.second+dy[i];
                if(isValid(newX,newY,grid,visited)){
                    q.push({newX,newY});
                    visited[newX][newY]=1;
                    distance[newX][newY]=min(distance[newX][newY],distance[curr.first][curr.second]+1);
                }
            }
            
        }
        if(distance[grid.size()-1][grid.size()-1]==1e9)
            return -1;
        return distance[grid.size()-1][grid.size()-1];
    }
};