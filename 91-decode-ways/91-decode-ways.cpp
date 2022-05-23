class Solution {
public:
    int solve(string s,int index,vector<int>& dp){
        //base case
        if(index<0)
            return 1;
        // if(s[index]=='0')
        //     return 0;
        if(index==0)
            return 1;
        map<string,char> mp;
        char t='A';
        for(int i=1;i<=26;i++){
            mp[to_string(i)]=t++;
        }
        // cout<<s[index]<<"\n";
        if(dp[index]!=-1)
            return dp[index];
        int forOne=0;
        if(s[index]!='0')
        forOne=solve(s,index-1,dp);
        int forTwo=0;
            string numb;
                numb=s[index-1];
            numb+=s[index];
            // cout<<numb<<" "<<s[index-1]<<" "<<s[index]<<"\n";
            if(mp.find(numb)!=mp.end()){
                forTwo=solve(s,index-2,dp);
            }
        return dp[index]=forOne+forTwo;
    }
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0')
            return 0;
        vector<int> dp(n+1,-1);
        int res=solve(s,n-1,dp);
        return res;
    }
};