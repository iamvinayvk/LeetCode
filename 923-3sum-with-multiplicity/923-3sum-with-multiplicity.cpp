class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<long long ,long long > mp;
        long long ans=0;
        long long mod=1e9+7;
        sort(arr.begin(),arr.end());
        for(auto x:arr){
            mp[x]++;
        }
        for(int i=0;i<arr.size();i+=mp[arr[i]]){
            int lo=i,hi=arr.size()-1;
            long long sum=target-arr[i];
            while(lo<hi){
                if(arr[lo]+arr[hi]==sum){
                    cout<<arr[i]<<" "<<arr[lo]<<" "<<arr[hi]<<"\n";
                    if(arr[i]!=arr[lo]&&arr[lo]!=arr[hi]&&arr[i]!=arr[hi]){
                        ans+=(mp[arr[i]]*mp[arr[lo]]*mp[arr[hi]]);
                    }
                    else if(arr[i]==arr[lo]&&arr[lo]!=arr[hi]){
                        ans+=(mp[arr[i]]*(mp[arr[i]]-1)*mp[arr[hi]]/2);
                    }
                    else if(arr[i]!=arr[lo]&&arr[lo]==arr[hi]){
                        ans+=(mp[arr[lo]]*(mp[arr[lo]]-1)*mp[arr[i]]/2);
                    }
                    else
                    {
                        ans+=(mp[arr[i]]*(mp[arr[i]]-1)*(mp[arr[i]]-2))/6;
                    }
                    cout<<ans<<"\n";
                    lo+=mp[arr[lo]],hi-=mp[arr[hi]];
                }
                else if(arr[lo]+arr[hi]<sum){
                    lo+=mp[arr[lo]];
                }
                else{
                    hi-=mp[arr[hi]];
                }
            }
            
        }
        return ans%mod;
    }
};