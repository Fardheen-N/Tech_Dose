class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1;
        int n = nums.size();
        vector<int> pre,suf(nums.size());
        
        for(auto i:nums){
            pre.push_back(pro);
            pro*=i;
        }
        
        pro=1;
        
        for(int i=n-1;i>=0;i--){
            suf[i]=pro;
            pro*=nums[i];
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back(pre[i]*suf[i]);
        }
        return res;
    }
};