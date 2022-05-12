class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackIndex=0;
        while(haystackIndex<haystack.size()){
            int needleIndex=0;
            int tempIndex=haystackIndex;
            while(needleIndex<needle.size()&&tempIndex<haystack.size()){
                if(haystack[tempIndex]==needle[needleIndex]){
                    tempIndex++,needleIndex++;
                }
                else{
                    break;
                }
            }
            haystackIndex++;
            if(needleIndex==needle.size())
                return haystackIndex-1;
        
        }
        return -1;
        
    
    }
};