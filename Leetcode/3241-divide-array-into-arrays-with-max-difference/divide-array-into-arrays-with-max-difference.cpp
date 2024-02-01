class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int pi = 0;
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-nums[pi]<=k){
                temp.push_back(nums[i]);
            }
            if(temp.size()==3){
                res.push_back(temp);
                temp.clear();
                pi=i+1;
            }
        }
        if(res.size()*3==nums.size()) return res;
        else return {};
    }
};