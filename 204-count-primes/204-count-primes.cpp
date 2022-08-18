class Solution {
public:

    int countPrimes(int n) {
        int ans=0;
        vector<bool> isPrime(n+1,false);
            if(n>2)
                ans++;
            
      for(long long i=3;i<n;i+=2){
          if(!isPrime[i]){
              ans++;
              // cout<<i<<" ";
            
    for(long long  j=i*i;j<n;j+=i){
                  isPrime[j]=true;
              }
              

          }
      }
        return ans;
    }
};