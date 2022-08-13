class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int windowSize=words.size()*words[0].size();
        vector<int> ans;
        map<string,int> countWords,currentCount;
        for(int i=0;i<words.size();i++){
            countWords[words[i]]++;
        }
        int start=0;
        while(start<s.size()-windowSize+1){
            int flag=0;
            currentCount=countWords;
            for(int i=start;i<start+windowSize&&i<s.size();i+=words[0].size()){
            string str=s.substr(i,words[0].size());
            // cout<<str<<" "<<start<<" ";
            if(currentCount.find(str)!=currentCount.end()){
                if(currentCount[str]==0){
                    flag=1;
                    break;  
                }
                currentCount[str]--;
                
            }
            else{
                flag=1;
                break;   
            }

        }
            // cout<<"\n";

        if(flag==0)
            ans.push_back(start);
            start++;
        }
        return ans;
        
    }
    
};
