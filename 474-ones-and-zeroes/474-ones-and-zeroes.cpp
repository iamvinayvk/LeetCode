class Solution {
public:
    int knapSack(vector<string>& strs,int m,int n,int index,map<string,vector<int>>& store,vector<vector<vector<int>>>& dp){
        //basecase
       
        if(index==-1||(m<=0 && n<=0)){
         
            return 0;
        }
//         if(index==0)
//         {
//            int one=store[strs[index]][0];
//         int zero=store[strs[index]][1];
//            if(m-zero>=0&&n-one>=0){
//                cout<<"gaya\n";
//                return 1;
//            }
               
//             else
//                 return 0;
//         } 
        int one=store[strs[index]][0];
        int zero=store[strs[index]][1];
        int take=INT_MIN;
        if(dp[m][n][index]!=-1)
            return dp[m][n][index];
        if(m<zero||n<one)
        {
            return dp[m][n][index]=knapSack(strs,m,n,index-1,store,dp);
        }
        take=1+knapSack(strs,m-zero,n-one,index-1,store,dp);
        int notTake=knapSack(strs,m,n,index-1,store,dp);
        // cout<<"take: "<<take<<" "<<"notTake: "<<notTake<<" "<<index<<" "<<m<<" "<<n<<"\n";              
        return dp[m][n][index]=max(take,notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        map<string,vector<int>> store;
        for(int i=0;i<strs.size();i++){
            int one=0,zero=0;
            for(int j=0;j<strs[i].size();j++){
                strs[i][j]=='1'?one++:zero++;
            }
            // cout<<one<<" "<<zero<<"\n";
            store[strs[i]].push_back(one);
            store[strs[i]].push_back(zero);

        }
        int size=strs.size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(size+1,-1)));
        int res=knapSack(strs,m,n,size-1,store,dp);
        return res;
    }
};