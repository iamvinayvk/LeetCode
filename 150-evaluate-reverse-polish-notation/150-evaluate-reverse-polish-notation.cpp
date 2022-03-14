class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int ans;
        for(int i=0;i<tokens.size();i++){
            st.push(tokens[i]);
            if(st.top()=="/"){
                st.pop();
                int val1=stoi(st.top());
                st.pop();
                int val2=stoi(st.top());
                st.pop();
                ans=val2/val1;
                st.push(to_string(ans));
                
                
            }
            else if(st.top()=="*"){
                st.pop();
                int val1=stoi(st.top());
                st.pop();
                int val2=stoi(st.top());
                st.pop();
                ans=val2*val1;
                st.push(to_string(ans));
                
            }
            else if(st.top()=="+"){
                st.pop();
                int val1=stoi(st.top());
                st.pop();
                int val2=stoi(st.top());
                st.pop();
                ans=val2+val1;
                st.push(to_string(ans));
                
            }
            else if(st.top()=="-"){
                st.pop();
                int val1=stoi(st.top());
                st.pop();
                int val2=stoi(st.top());
                st.pop();
                ans=val2-val1;
                st.push(to_string(ans));
                
            }
        }
        ans=stoi(st.top());
        return ans;
    }
};