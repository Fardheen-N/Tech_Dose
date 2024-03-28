class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        int res = 0;
        int l=0;
        int maxFreq = 0,ele =nums[0];
        for(int r=0;r<n;r++){
            mp[nums[r]]++;
            if(mp[nums[r]]>maxFreq) {maxFreq = mp[nums[r]];ele = nums[r];}
            while(mp[ele]>k && l<r){
                mp[nums[l]]--;
                l++;
            }
            maxFreq = mp[ele];
            int len = r-l+1;
            res = max(len,res);
        }
        return res;
    }
    int check(map<int,int> &mp,int k){
        for(auto [key,val]:mp){
            if(val>k) return key;
        }
        return -1;
    }
};