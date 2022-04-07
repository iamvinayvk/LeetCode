class Solution {
public:
    static bool cmp(int& a,int& b){
        return a>b;
    }
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end(),cmp);
        for(int i=0;i<stones.size()-1;i++){
            sort(stones.begin()+i,stones.end(),cmp);
            for(auto x:stones){
                cout<<x<<" ";
            
            }
            cout<<"\n";
            if(stones[i]==stones[i+1]){
                stones[i]=0;
                stones[i+1]=0;
                i++;
            }
            else{
                stones[i+1]=stones[i]-stones[i+1];
                stones[i]=0;
            }
            
            // cout<<stones[i]<<" "<<stones[i+1]<<"\n";
        }
        return stones[stones.size()-1];
    }
};