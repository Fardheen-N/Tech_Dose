class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int> mp;
        int n = nums.size();
        int res = 0;
        int l=0;
        for(int r=0;r<n;r++){
            mp[nums[r]]++;
            while(mp[nums[r]]>k && l<r){
                mp[nums[l++]]--;
            }
            int len = r-l+1;
            res = max(len,res);
        }
        return res;
    }
};