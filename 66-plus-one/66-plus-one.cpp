class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry=0;
        int one=1;
        for(int i=digits.size()-1;i>=0;i--){
            ans.push_back((digits[i]+carry+one)%10);
            carry=(digits[i]+one+carry)/10;
            one=0;
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};