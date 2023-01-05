//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin(),words.end());
        map<string,int> mp;
        for(auto x:words){
            mp[x]++;
        }
        string ans="";
        for(int i=0;i<words.size();i++){
            bool flag=true;
            string w=words[i];
            for(int j=0;j<w.size();j++){
                string x=w.substr(0,j+1);
                if(mp.find(x)==mp.end()){
                    flag=false;
                    break;
                }
            }
            if(flag&&w.size()>ans.size()){
                ans=w;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends