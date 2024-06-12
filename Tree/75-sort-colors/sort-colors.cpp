class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = nums.size()-1;
        int l = 0;
        int mid = 0;
        while(mid<=r){
            if(nums[mid]==0){
                swap(nums[l],nums[mid]);
                l++;
                mid++;
            }else if(nums[mid]==2){
                swap(nums[mid],nums[r]);
                r--;
            }
            else mid++;
        }
        return;
    }
};