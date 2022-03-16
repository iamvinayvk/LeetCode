class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> input;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            input.push(pushed[i]);
            while(!input.empty()&&j<popped.size()&&popped[j]==input.top()){
                input.pop();
                j++;
            }
        }
        if(input.empty()){
            return true;
        }
        return false;
    }
};