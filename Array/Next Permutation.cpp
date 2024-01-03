#define all(X) (X).begin(),(X).end()
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(all(nums));
    }
};
