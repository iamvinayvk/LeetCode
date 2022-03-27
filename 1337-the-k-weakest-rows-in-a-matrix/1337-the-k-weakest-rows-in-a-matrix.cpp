class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> store;
        for(int i=0;i<mat.size();i++){
            int count=0;
            int l=0,j=mat[i].size()-1;
            int index=0;
            while(l<=j){
                int mid=l+(j-l)/2;
                if(mat[i][mid]==1){
                    l=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
            // cout<<"l: "<<l<<"\n";
            store.push_back({l,i});
        }
        sort(store.begin(),store.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(store[i].second);
        }
        return ans;
    }
};