class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp1[nums1[i]+nums2[j]]++;
                mp2[nums3[i]+nums4[j]]++;
            }
        }
        for(auto &[sum,freq]:mp1){
            if(mp2[-sum]){
                res+=(freq*mp2[-sum]);
            }
        }
        return res;
    }
};