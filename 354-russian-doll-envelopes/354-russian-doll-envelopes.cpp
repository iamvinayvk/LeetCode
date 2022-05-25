class Solution {
public:
//     int maxE(vector<vector<int>>& envelopes,int n,int maxW,int maxH){
//         //base case
//         if(n<0)
//             return 0;
        
        
//         int take=INT_MIN,notTake=INT_MIN;
//         int currW=envelopes[n][0],currH=envelopes[n][1];
//         if(currW<maxW&&currH<maxH)
//         {
//             cout<<n<<" "<<currW<<" "<<currH<<"\n";
//             take=1+maxE(envelopes,n-1,currW,currH);
//         }
//         notTake=maxE(envelopes,n-1,maxW,maxH);
        
//         return max(take,notTake);
//     }
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> lis;
        // cout<<"Printing\n";
        // for(auto x:envelopes){
        //     cout<<x[0]<<" "<<x[1]<<"\n";
        // }
        for(int i=0;i<n;i++){
            auto it=lower_bound(lis.begin(),lis.end(),envelopes[i][1]);
            if(it==lis.end()){
                lis.push_back(envelopes[i][1]);
            }
            else{
                lis[it-lis.begin()]=envelopes[i][1];
            }
            // cout<<"Printing LIS\n";
            // for(auto x:lis){
            //     cout<<x<<" ";
            // }
            // cout<<"\n";
        }
        return lis.size();
    }
};