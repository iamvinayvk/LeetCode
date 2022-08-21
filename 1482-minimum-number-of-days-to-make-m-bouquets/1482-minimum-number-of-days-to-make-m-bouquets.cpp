class Solution {
public:
    bool isBloom(long long midDay,vector<int>& bloomDay,int m,int k){
        int currentK=0;
        int bouqe=0;
        // cout<<"midDay: "<<midDay<<"\n";
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]>midDay)
                currentK=0;
            if(bloomDay[i]<=midDay&&currentK<k){
                currentK++;
                if(currentK==k){
                    currentK=0;
                    bouqe++;
                }
            }

        }
        return bouqe>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int startDay=1,endDay=1e10;
        long long int ans=-1;
        while(startDay<endDay){
            long long int midDay=startDay+(endDay-startDay)/2;
            if(isBloom(midDay,bloomDay,m,k)){
                endDay=midDay;
                ans=endDay;
            }
            else{
                startDay=midDay+1;
            }
        }
        return ans;
    }
};