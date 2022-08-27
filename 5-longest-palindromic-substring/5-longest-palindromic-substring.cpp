class Solution {
public:
    bool ans(string& s,int i,int j,vector<vector<int>>& dp){
        if(dp[i][j]!=-1)
            return dp[i][j];
        int st=i,en=j;
        while(st<en){
            if(s[st++]!=s[en--])
                return dp[i][j]=false;
        }
        return dp[i][j]=true;
    }
    string longestPalindrome(string s) {
        string res="";
        int start=0,end=0;
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n-1;i++)
            dp[i][i]=1,dp[i][i+1]=s[i]==s[i+1];
        dp[n-1][n-1]=1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                bool made=ans(s,i,j,dp);
                if(made&&(j-i>=end-start)){
                    start=i,end=j;
                }  
            }
        }
        for(int i=start;i<=end;i++)
            res.push_back(s[i]);
        // for(int i=start;i<=end;i++)
        //         res+=s[i];
        return res;
        
    }
};