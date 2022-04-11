class Solution {
public:
    bool isPalindrome(int x) {
    string number =to_string(x);
    int i=0,j=number.size()-1;
        while(i<j){
            if(number[i++]!=number[j--]){
                return false;
                
            }
            
        }
        return true;
        
    }
};