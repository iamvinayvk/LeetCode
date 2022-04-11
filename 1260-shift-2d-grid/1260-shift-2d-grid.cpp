class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> res;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                res.push_back(grid[i][j]);
            }
        }
        k=k%(m*n);
        rotate(res.begin(), res.begin()+res.size()-k, res.end());
        int l=0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                grid[i][j] = res[l];
                l++;
            }
        }
        return grid;
    }
};