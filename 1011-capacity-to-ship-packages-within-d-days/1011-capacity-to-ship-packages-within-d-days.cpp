class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //Time Complexity : O(n*(log(totalSum)))
        //Space Complexity: O(1)
        int startSum=1;
        int lastSum=0;
        int ans=0;
        // sort(weights.begin(),weights.end());
        for(int i=0;i<weights.size();i++){
            lastSum+=weights[i];
        }
        //binary searched on the total sum search space
        while(startSum<=lastSum){
            int midSum=startSum+(lastSum-startSum)/2;
            if(isPossible(midSum,days,weights)){
                // cout<<startSum<<" "<<midSum<<" "<<lastSum<<"\n";
                //if found the sum the reduced the search space from right
                ans=midSum;
                lastSum=midSum-1;
            }
            else{
                // cout<<startSum<<" "<<lastSum<<"\n";
                //if not found then reduced the search space  from left
                startSum=midSum+1;
            }
        }
        return ans;
        
    }
    bool isPossible(int midSum,int days,vector<int>& weights){
        int requiredDays=1;
        int currWeight=0;
        // storing the contiguous sum 
        for(int i=0;i<weights.size();i++){
            //checking if the reuried days is greater than the given days
            // or if the weight of individual weight is greater then it not possible to ship that weight
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