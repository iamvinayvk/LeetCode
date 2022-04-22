// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findAns(int N,vector<vector<int>>& Matrix,int r,int c,vector<vector<int>>& dp){
        if(r>=N||c>=N||r<0||c<0)
        {
            return 0;
        }
        return Matrix[r][c]+max(max(dp[r+1][c]==0?dp[r+1][c]=findAns(N,Matrix,r+1,c,dp):dp[r+1][c],dp[r+1][c-1]==0?dp[r+1][c-1]=findAns(N,Matrix,r+1,c-1,dp):dp[r+1][c-1]),dp[r+1][c+1]==0?dp[r+1][c+1]=findAns(N,Matrix,r+1,c+1,dp):dp[r+1][c+1]);
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int ans=0;
        vector<vector<int>> dp(N+1,vector<int>(N+1,0));
        for(int i=0;i<N;i++){
            ans=max(ans,findAns(N,Matrix,0,i,dp));
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends