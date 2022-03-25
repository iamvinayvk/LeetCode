class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1));
        //for single character setting it as true for palindrome
        pair<int,int> ans;
        for(int i=0;i<s.size();i++){
            dp[i][i]=1;
            ans.first=i;
            ans.second=i;
        }
        // for two length string 
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                ans.first=i;
                ans.second=i+1;
            }
            else{
                dp[i][i+1]=0;
            }
        }
        // now checking if the the previous string i+1 and j-1 are equal or not 
        int k=2;
        
        while(k<s.size()){
            int i=0;
            int j=i+k;
            for(;j<s.size();j++){
                if(s[i]==s[j]&&dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    ans.first=i;
                    ans.second=j;
                }
                else{
                    dp[i][j]=0;
                }
                i++;
            }
            k++;
            
        }
        string res;
        for(int i=ans.first;i<=ans.second;i++)
        {
            res+=s[i];
        }
        return res;
    }
};