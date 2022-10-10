class Solution {
public:
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
        
    }
    string breakPalindrome(string palindrome) {
        
        if(palindrome.size()==1)
            return "";
        for(int i=0;i<palindrome.size();i++){
           if(palindrome[i]!='a'){
               char temp=palindrome[i];
               palindrome[i]='a';
               if(isPalindrome(palindrome)==false)
               return palindrome;
               palindrome[i]=temp;
           } 
        }
        palindrome[palindrome.size()-1]='b';
        return palindrome;
        
        
    }
};