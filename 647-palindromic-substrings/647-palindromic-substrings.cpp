class Solution {
public:
    int isPalindrome(string s,int i,int j,vector<vector<int>>& dp){
        if(dp[i][j]!=-1)
            return dp[i][j];
        int st=i,e=j;
        while(st<e){
            if(s[st++]!=s[e--])
                return dp[i][j]=false;
        }
        return dp[i][j]=true;
        
    }
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans+=(isPalindrome(s,i,j,dp));
            }
        }
        return ans;
    }
};