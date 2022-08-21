class Solution {
public:
    bool isEaten(int midB,vector<int>& piles,int h){
        int ih=0;
        for(int i=0;i<piles.size();i++){
            ih+=piles[i]/midB;
            if(piles[i]%midB)
                ih+=1;
           
        }
        return ih<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int startB=1,lastB=1e9;
        while(startB<lastB){
            int midB=startB+(lastB-startB)/2;
            if(isEaten(midB,piles,h)){
                lastB=midB;
            }
            else{
                startB=midB+1;
            }
        }
        return lastB;
    }
};