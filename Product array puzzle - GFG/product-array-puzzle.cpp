// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long> prefixProduct(nums.size()+1,1),suffixProduct(nums.size()+1,1);
        for(int i=0;i<nums.size();i++){
            prefixProduct[i+1]=prefixProduct[i]*nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            suffixProduct[i]=suffixProduct[i+1]*nums[i];
        }
        vector<long long> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(prefixProduct[i]*suffixProduct[i+1]);
        }
        return ans;
        //code here        
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends