class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        generateAll(curr,0,0,ans,n);
        return ans;
        
    }
    void generateAll(string curr,int open,int close,vector<string>& ans,int n){
        if(2*n==curr.length()){
            if(isValid(curr)){
                ans.push_back(curr);
                return ;
            }
        }
        if(open<n){
          curr+='(';
            generateAll(curr,open+1,close,ans,n); 
            curr.erase(curr.end()-1);
        }
        if(close<open){
           curr+=')';
            generateAll(curr,open,close+1,ans,n); 
            curr.erase(curr.end()-1);
        }
            
            
        
    }
    bool isValid(string curr){
        int val=0;
        for(auto c:curr){
            if(c=='('){
                val++;
            }
            else{
                val--;
            }
            if(val<0)
                return false;
        }
        return val==0;
    }
};