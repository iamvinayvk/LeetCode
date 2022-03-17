class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        vector<string> rows(numRows);
        bool down=false;
        int currRow=0;
        for(char c:s){
            rows[currRow]+=c;
            if(currRow==0||currRow==numRows-1){
                down=!down;
            }
            currRow+=down?1:-1;
        }
        string ans;
        for(auto r:rows){
            ans+=r;
        }
        return ans;
    }
};