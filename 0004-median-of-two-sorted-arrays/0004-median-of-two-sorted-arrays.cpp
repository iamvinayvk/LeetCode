class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        int m=nums1.size(),n=nums2.size();
        vector<int> res;
        int i=0,j=0;
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            res.push_back(nums1[i++]);
        }
        while(j<n){
            res.push_back(nums2[j++]);
        }
        
        if((n+m)%2){
     ans=res[(n+m)/2];
        }
        else{
        
            ans=(double)(res[(n+m-1)/2]+res[(n+m)/2])/2;
        }
        return ans;
        
        
    }
};