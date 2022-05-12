class Solution {
public:
            vector<int> temp,t;

    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            t.push_back(nums[i]);
            temp.push_back(nums[i]);
        }
    }
    
    vector<int> reset() {
        return t;
    }
    
    vector<int> shuffle() {
         vector<int> result(t);
        for (int i = 0;i < result.size();i++) {
            int pos = rand()%(result.size()-i);
            swap(result[i+pos], result[i]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */