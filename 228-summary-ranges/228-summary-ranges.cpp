class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            string s="";
            s+=to_string(nums[i]);
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j-1]+1!=nums[j])
                {
                    cout<<j<<" "<<nums[j-1]<<" "<<nums[j]<<"\n";
                    cout<<"gaya\n";
                    if(nums[i]==nums[j-1])
                    {
                        i=j-1;
                        break;
                    }
                    else
                    {
                        s+="->";
                        s+=to_string(nums[j-1]);
                        i=j-1;
                        break;
                    }
                }
                if(j==nums.size()-1)
                {
                   s+="->";
                        s+=to_string(nums[j]);
                        i=j;
                        break; 
                }
            }
            ans.push_back(s);
            
        }
        return ans;
    }
};