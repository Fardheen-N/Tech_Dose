#define all(X) (X).begin(),(X).end()
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(all(nums));
        int ind = -1;
        int n =nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(all(nums));
        }
        else{
            for(int i=n-1;i>=ind;i--){
                if(nums[i]>nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            reverse(nums.begin()+ind+1,nums.end());
        }
    }
};