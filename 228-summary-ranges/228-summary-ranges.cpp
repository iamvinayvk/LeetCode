class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        //Time Complexity : O(n^2)
        //Space Complexity :O(n) ignoring the ans vector
        
        for(int i=0;i<nums.size();i++)
        {
            string s="";
            // first loop is used to store the starting element
            s+=to_string(nums[i]);
            for(int j=i+1;j<nums.size();j++)
            {
                // if they are not successive elements 
                if(nums[j-1]+1!=nums[j])
                {
                    //if they are equal then it is already stored in s and we have to break
                    if(nums[i]==nums[j-1])
                    {
                        i=j-1;
                        break;
                    }
                    //it means the index is not stored and we have to store it and it is the final element
                    else
                    {
                        s+="->";
                        s+=to_string(nums[j-1]);
                        i=j-1;
                        break;
                    }
                }
                //it used to check the last elemnt is it successive then we have to store it also
                if(j==nums.size()-1)
                {
                        s+="->";
                        s+=to_string(nums[j]);
                        i=j;
                }
            }
            ans.push_back(s);
            
        }
        return ans;
    }
};