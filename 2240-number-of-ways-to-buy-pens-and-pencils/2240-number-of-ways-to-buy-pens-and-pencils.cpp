class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if(total<cost1&&total<cost2){
            return 1;
        }
        int pen=0,pencil=0;
        int penT=total;
        long long ans=0;
      
            // ans+=total%cost1==0?1:0;
        long long x=total/cost1;
            while(x>=0){
                ans+=(total/cost2);
                
                ans++;
                total-=cost1;
                x--;

                // cout<<ans<<"\n";
                
            }
        
        
        total=penT;
        
        return ans;
        
    }
};