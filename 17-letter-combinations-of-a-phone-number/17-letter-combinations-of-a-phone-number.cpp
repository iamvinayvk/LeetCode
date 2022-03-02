class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
        if(digits.empty())
        {
            return {};
        }
        vector<string> ans{""};
        for(auto digit:digits){
            vector<string> temp=ans;
            for(auto tem:temp){
                // cout<<"gaya\n";
                for(auto map:mapping[digit-'0']){
                    // cout<<"gaya\n";
                ans.push_back(tem+map);
            }
            }
            
        }
        vector<string> realAns;
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()==digits.size())
                realAns.push_back(ans[i]);
        }
        
        return realAns;
    }
};