class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss,tt;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'&&ss.empty()==false){
                ss.pop();
            }
            else if(s[i]!='#') {
                ss.push(s[i]);
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'&&tt.empty()==false){
                tt.pop();
            }
            else if(t[i]!='#'){
                tt.push(t[i]);
            }
        }
        if(ss.size()!=tt.size())
            return false;
        while((!ss.empty())&&(!tt.empty())){
            // if(ss.size()!=tt.size()){
            //     return false;
            // }
            // cout<<ss.top()<<" "<<tt.top()<<"\n";
            if(ss.top()!=tt.top()){
                return false;
            }
            ss.pop();
            tt.pop();
        }
        return true;
    }
};