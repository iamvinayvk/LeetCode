class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i,start=0;
        map<char,int> mp;
        for(i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end()){
                break;
            }
            mp[s[i]]++;
        }
        ans=max(ans,(int)mp.size());
        for(;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end())
                mp[s[start++]]--;
            if(mp[s[start-1]]==0)
                mp.erase(s[start-1]);
            while(mp[s[i]]>0){
                mp[s[start++]]--;
                if(mp[s[start-1]]==0)
                    mp.erase(s[start-1]);
            }
                
            mp.erase(s[i]);
            mp[s[i]]++;
          
            ans=max(ans,(int)mp.size());
        }
        return ans;
    }
};