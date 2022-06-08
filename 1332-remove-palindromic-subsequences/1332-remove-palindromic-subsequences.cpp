class Solution {
public:
    int removePalindromeSub(string s) {
        int ans=1;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                ans=2;
                break;
            }
        }
        return ans;
        
    }
};