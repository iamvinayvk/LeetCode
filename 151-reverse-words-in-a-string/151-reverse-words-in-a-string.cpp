class Solution {
public:
    void r(string& temp){
        int i=0,j=temp.size()-1;
        while(i<j){
            swap(temp[i++],temp[j--]);
        }
    }
    string reverseWords(string s) {
        string ans;
        string temp;
        for(int i=s.size()-1;i>=0;i--){
            
            if(s[i]==' '){
                while(i>=0&&s[i]==' '){
                    i--;
                }
                i+=1;
                if(temp=="")
                {
                    continue;
                }
                r(temp);
                ans+=temp;
                ans+=' ';
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
                r(temp);
                ans+=temp;
                ans+=' ';
                temp="";
        while(ans.back()==' '){
            ans.pop_back();
        }
        
        return ans;
    }
};