class Solution {
public:
    void setZ(vector<vector<int>>& matrix,int row,int column){
        //set rows to zero
        for(int i=0;i<matrix[row].size();i++){
            matrix[row][i]=0;
        }
        //set Column to zero
        for(int i=0;i<matrix.size();i++){
            matrix[i][column]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        //Time Complexity : O(mn)
        //Space Complexity : O(Z) where Z is number of Zeroes
        vector<pair<int,int>> storeZeroes;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                {
                    storeZeroes.push_back({i,j});
                }
            }
        }
        for(int i=0;i<storeZeroes.size();i++){
            setZ(matrix,storeZeroes[i].first,storeZeroes[i].second);
        }
    }
};