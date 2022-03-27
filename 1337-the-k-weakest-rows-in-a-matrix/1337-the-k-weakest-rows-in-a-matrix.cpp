class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> store;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[i].size();j++){
                count+=mat[i][j];
            }
            store.push_back({count,i});
        }
        sort(store.begin(),store.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(store[i].second);
        }
        return ans;
    }
};