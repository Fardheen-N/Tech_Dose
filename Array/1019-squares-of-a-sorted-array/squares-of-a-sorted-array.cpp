class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int> set;
        for(auto i:nums){
            set.insert(i*i);
        }
        return {set.begin(),set.end()};
    }
};