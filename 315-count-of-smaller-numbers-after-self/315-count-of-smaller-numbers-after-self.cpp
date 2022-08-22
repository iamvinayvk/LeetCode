#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n);
        pbds st;
        for(int i = n - 1; i >= 0; i--) {
            st.insert(nums[i]);
            counts[i] = st.order_of_key(nums[i]);
            
        }
        return counts;
    }
};
