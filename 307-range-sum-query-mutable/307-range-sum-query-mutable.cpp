class NumArray {
public:
    vector<int> a;
    vector<int> block;
    int len;
    NumArray(vector<int>& nums) {
        for(auto x:nums)
            a.push_back(x);
        int l=ceil(sqrt(nums.size()));
        len=l;
        block.resize(nums.size()/l+1);
        for(int i=0;i<nums.size();i++){
            block[i/l]+=a[i];
        }
    }
    
    void update(int index, int val) {
    
        block[index/len]=block[index/len]-a[index]+val;
        a[index]=val;
    }
    
    int sumRange(int left, int right) {
        int ans=0;
        int startBlock=left/len;
        int endBlock=right/len;
        if(startBlock==endBlock){
            for(int i=left;i<=right;i++){
                ans+=a[i];
            }
        }
        else{
            for(int i=left;i<(startBlock+1)*len;i++){
                ans+=a[i];
            }
            for(int i=startBlock+1;i<endBlock;i++){
                ans+=block[i];
            }
            for(int i=endBlock*len;i<=right;i++)
                ans+=a[i];
        }
        
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */