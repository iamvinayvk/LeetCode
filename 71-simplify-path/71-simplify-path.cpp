class Solution {
public:
    string simplifyPath(string path) {
        int currentLevel=0;
        string canonicalString="/";
        for(int i=1;i<path.size();i++)
        {
            if(canonicalString.size()==0)
                canonicalString+='/';
            if(path[i]=='/')
                continue;
            int j=i;
            for(;j<path.size();j++)
            {
                if(path[j]=='/')
                {
                    break;
                }
                
                
                    
            }
            // cout<<j<<" "<<path<<"\n";
            int flag=0;
            
            if(path[j-1]=='.'&&path[j-2]=='.'&&(path[j-3]=='/'))
                {
                    // cout<<"gaya\n";
                    flag=1;
                    currentLevel--;
                }
             else if(path[j-1]=='.'&&(path[j-2]=='/'))
                {
                 i=j;
                continue;
                }
            
                if(currentLevel<0)
                {
                    currentLevel=0;
                    i=j;
                    continue;
                }
                if(flag)
                {
                    if(canonicalString.size()>0)
                    canonicalString.erase(canonicalString.size()-1);
                    while(canonicalString.size()>0&&canonicalString.back()!='/')
                    {
                        canonicalString.erase(canonicalString.size()-1);
                    }
                    i=j;
                    continue;
                
                }
            cout<<canonicalString<<"\n";
            if(canonicalString.size())
                for(int k=i;k<=j&&k<path.size();k++)
                {
                    // cout<<path[k]<<" "<<k<<"\n";
                    currentLevel++;
                    canonicalString+=path[k];
                }
            i=j;
            
        }
        if(canonicalString.back()=='/')
        {
            canonicalString.erase(canonicalString.size()-1);
        }
        if(canonicalString.size()==0)
                canonicalString+='/';
        return canonicalString;
    }
};