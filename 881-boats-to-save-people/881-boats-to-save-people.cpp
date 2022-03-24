class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int maxWeight=people.size()-1;
        int minWeight=0;
        int ans=0;
        while(minWeight<=maxWeight){
            if(people[minWeight]+people[maxWeight]<=limit){
                minWeight++;
                maxWeight--;
            }
            else{
                maxWeight--;
            }
            ans++;
        }
        return ans;
    }
};