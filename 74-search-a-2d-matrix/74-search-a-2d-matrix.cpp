class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
        int m=matrix[0].size();
        int l=0,r=n-1;
        int mid=l+(r-l)/2;
        while(l<=r)
        {
            mid=l+(r-l)/2;
    
            
            if(matrix[mid][0]<=target&&matrix[mid][m-1]>=target)
            {
                // cout<<"your\n";
               int s=0,e=m-1;
                while(s<=e)
                {
                    
                    int mid1=s+(e-s)/2;
                    if(matrix[mid][mid1]==target)
                        return true;
                    else if(matrix[mid][mid1]>target)
                    {
                       e=mid1-1; 
                    }
                    else
                        s=mid1+1;
                }
                return false;
            }
            else if(matrix[mid][0]>target)
            {
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return false;
    }
};