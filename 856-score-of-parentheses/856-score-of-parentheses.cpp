class Solution {
public:
    int scoreOfParentheses(string s) {
        int deep=0;
        int ans=0;
        int f=1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                deep++;
            else{
                deep--;
                if(s[i-1]=='(')
                    ans+=(1<<deep);
            }
        }
        return ans;
        
    }
};