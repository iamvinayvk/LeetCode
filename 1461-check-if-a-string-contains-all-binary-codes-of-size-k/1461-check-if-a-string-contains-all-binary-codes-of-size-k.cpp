class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need=1<<k;
        map<string,int> comb;
        for(int i=0;i<s.size();i++){
            string temp;
            for(int j=i;j<i+k&&j<s.size();j++){
                temp+=s[j];
            }
            if(temp.size()==k){
                comb[temp]++;
            }
        }
        if(comb.size()==need)
        return true;
        
            return false;

    }
};