class NumArray {
private:
    void build(vector<int> &nums,int idx,int low,int high){
        if(low == high){
            seg[idx] = nums[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(nums,2*idx+1,low,mid);
        build(nums,2*idx+2,mid+1,high);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    int updateseg(int idx,int low,int high,int targetIdx,int val){
        if(low == targetIdx && high == targetIdx){
            return seg[idx] = val;
        }
        if(low > targetIdx || high < targetIdx) return seg[idx];

        int mid = low + (high - low) / 2;

        int left = updateseg(2*idx+1,low,mid,targetIdx,val);
        int right = updateseg(2*idx+2,mid+1,high,targetIdx,val);
        seg[idx] = left + right;
        return seg[idx];
    }

    int query(int idx,int low,int high,int l,int r){
        if(low >= l && high <= r){
            return seg[idx];
        }
        if(low > r || high < l) return 0;

        int mid = low + (high - low) / 2;

        int left = query(2*idx+1,low,mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);

        return left + right;
    }
public:
    vector<int> arr, seg;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        build(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        updateseg(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};