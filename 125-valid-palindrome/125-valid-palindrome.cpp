class Solution {
public:
    bool isPalindrome(string s) {
        
        string ss;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                ss+=tolower(s[i]);
            }
            else if(s[i]>='a'&&s[i]<='z'){
                ss+=s[i];
            }
            else if(s[i]>='0'&&s[i]<='9')
                ss+=s[i];
        }
        int i=0;
        int j=ss.size()-1;
        // cout<<i<<" "<<j<<"\n";
        // cout<<ss<<"\n";
        while(i<j){
            // if(ss[i]>='A'&&ss[i]<='Z'){
            //     char ch=tolower(ss[i]);
            // }
            // if(ss[i]>='A'&&ss[i]<='Z'){
            //     char ch=tolower(ss[i]);
            // }
            // cout<<ss[i]<<" "<<ss[j]<<"\n";
            if(ss[i++]!=ss[j--])
                return false;
        }
        return true;
    }
};