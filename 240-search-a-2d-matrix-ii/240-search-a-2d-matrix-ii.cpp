class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int low=0,high=matrix[0].size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                // cout<<low<<" "<<high<<" "<<mid<<"\n";
                if(matrix[i][mid]==target){
                    return true;
                }
                else if(matrix[i][mid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        // cout<<"\n\n";
        return false;
    }
};