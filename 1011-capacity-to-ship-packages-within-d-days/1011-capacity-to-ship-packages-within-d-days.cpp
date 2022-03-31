class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int startSum=1;
        int lastSum=0;
        int ans=0;
        // sort(weights.begin(),weights.end());
        for(int i=0;i<weights.size();i++){
            lastSum+=weights[i];
        }
        while(startSum<=lastSum){
            int midSum=startSum+(lastSum-startSum)/2;
            if(isPossible(midSum,days,weights)){
                // cout<<startSum<<" "<<midSum<<" "<<lastSum<<"\n";
                ans=midSum;
                lastSum=midSum-1;
            }
            else{
                // cout<<startSum<<" "<<lastSum<<"\n";
                startSum=midSum+1;
            }
        }
        return ans;
        
    }
    bool isPossible(int midSum,int days,vector<int>& weights){
        int requiredDays=1;
        int currWeight=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>midSum||requiredDays>days){
                // cout<<"midSum: "<<midSum<<" "<<weights[i]<<" "<<requiredDays<<"\n";
                return false;
            }
            if(currWeight+weights[i]<=midSum){
                currWeight+=weights[i];
            }
            else{
                currWeight=weights[i];
                requiredDays++;
                
            }
            // cout<<currWeight<<" "<<requiredDays<<" "<<midSum<<" :isPosssible"<<"\n";
        }
        if(requiredDays<=days){
            return true;
        }
        return false;
    }
};