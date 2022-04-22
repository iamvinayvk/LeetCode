// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool subset(vector<int>& arr,int currIndex,int lastIndex,int targetSum,vector<vector<int>>& dp){
    if(targetSum<0)
    return false;
    if(targetSum==0)
    return true;
    if(currIndex>lastIndex)
    return false;
    if(dp[currIndex][targetSum]!=-1)
    return dp[currIndex][targetSum];
    return dp[currIndex][targetSum]=(subset(arr,currIndex+1,lastIndex,targetSum-arr[currIndex],dp)||subset(arr,currIndex+1,lastIndex,targetSum,dp));
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> dp(arr.size(),vector<int>(sum+5,-1));
        return subset(arr,0,arr.size()-1,sum,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends