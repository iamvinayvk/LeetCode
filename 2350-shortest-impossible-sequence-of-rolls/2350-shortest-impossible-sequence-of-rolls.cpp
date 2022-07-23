class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int> s;
        int ans=0;
        for(int i=0;i<rolls.size();i++){
            s.insert(rolls[i]);
            if(s.size()==k)
            {
                ans++;
                s.clear();
            }
        }
        return ans+1;
    }
};