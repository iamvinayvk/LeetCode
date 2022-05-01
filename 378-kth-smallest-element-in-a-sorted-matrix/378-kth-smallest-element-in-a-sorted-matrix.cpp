class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> store;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                store.push_back(matrix[i][j]);
            }
        }
        sort(store.begin(),store.end());
        return store[k-1];
    }
};