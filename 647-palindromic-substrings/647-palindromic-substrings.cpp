class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int res=0;
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            res++;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(i+1==j){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                        res++;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if(s[i]==s[j]&&dp[i+1][j-1]==1){
                        dp[i][j]=1;
                        res++;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        return res;
        
    }
};