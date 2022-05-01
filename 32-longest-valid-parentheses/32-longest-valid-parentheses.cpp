class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0,close=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                close++;
            }
            if(open==close){
                int len=open+close;
                ans=max(len,ans);
            }
            if(close>open){
                open=0,close=0;
            }
        }
        open=0,close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                close++;
            }
            if(open==close){
                int len=open+close;
                ans=max(len,ans);
            }
            if(close<open){
                open=0,close=0;
            }
        }
        return ans;
    }
};