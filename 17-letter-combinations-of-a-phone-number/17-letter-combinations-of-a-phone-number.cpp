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
            vector<string> temp;
            for(auto tem:ans){
                // cout<<"gaya\n";
                for(auto map:mapping[digit-'0']){
                    // cout<<"gaya\n";
                temp.push_back(tem+map);
            }
                
            }
            ans=move(temp);
            
        }
        // vector<string> realAns;
        // for(int i=0;i<ans.size();i++){
        //     if(ans[i].size()==digits.size())
        //         realAns.push_back(ans[i]);
        // }
        
        return ans;
    }
};