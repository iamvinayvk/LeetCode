class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        k=k%(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[((i+(j+k)/n)%m)][(j+k)%n]=grid[i][j];
            }
        }
        //(i+(j+k)/n)%m is used to decide to the row j+k shifts determine the column and diving it by n gives the row and overflow is controlled by %m
        //(j+k)%n is dtermins the column of the new grid
        return ans;
        
        
    }
};