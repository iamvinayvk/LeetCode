class Solution {
public:
    bool isVowel(char s){
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='A'||s=='E'||s=='I'||s=='O'||s=='U'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int vowelInFirstHalf=0;
        int vowelInSecondHalf=0;
        for(int i=0;i<s.size();i++){
            if(2*i<s.size()){
                if(isVowel(s[i])){
                    vowelInFirstHalf++;
                }
            }
            else{
                if(isVowel(s[i])){
                    vowelInSecondHalf++;
                }
            }
        }
        return vowelInFirstHalf==vowelInSecondHalf;
    }
};