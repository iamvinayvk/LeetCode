class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //Time Complexity : O(nlogn)
        //Space Complexity : O(1)
        
        //sorted people in ascending ordere of their weight
        sort(people.begin(),people.end());
        //used this to store the index of maximum weight
        int maxWeight=people.size()-1;
        //used to store the index of minimum weight
        int minWeight=0;
        int ans=0;
        //using two pointers approach 
        while(minWeight<=maxWeight){
            //at most two persons can sit so checking the minimum and maximum weight 
            //if both satisfy the make them sit in one boat
            if(people[minWeight]+people[maxWeight]<=limit){
                minWeight++;
                maxWeight--;
            }
            //otherwise maximum weight person will sit alone
            else{
                maxWeight--;
            }
            ans++;
        }
        return ans;
    }
};