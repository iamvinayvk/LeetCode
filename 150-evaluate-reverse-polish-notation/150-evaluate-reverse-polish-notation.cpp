class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="/"&&tokens[i]!="*"&&tokens[i]!="+"&&tokens[i]!="-")
            st.push(stoi(tokens[i]));
            if(tokens[i]=="/"){
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                ans=val2/val1;
                st.push(ans);
                
                
            }
            else if(tokens[i]=="*"){
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                ans=val2*val1;
                st.push(ans);
                
            }
            else if(tokens[i]=="+"){
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                ans=val2+val1;
                st.push(ans);
                
            }
            else if(tokens[i]=="-"){
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                ans=val2-val1;
                st.push(ans);
                
            }
        }
        ans=st.top();
        return ans;
    }
};