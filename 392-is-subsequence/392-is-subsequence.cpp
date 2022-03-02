class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.size()==t.size())
        {
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!=t[i])
                    return false;
            }
            return true;
        }
        int j=0,i;
        for(i=0;i<s.size();i++){
            int flag=0;
            for(;j<t.size();j++)
            {
               if(s[i]==t[j])
               {
                   flag=1;
                   j++;
                   break;
               }
            }
            if(!flag)
            {
                return false;
            }
        }
        if(i==s.size())
        return true;
        return false;
    }
};