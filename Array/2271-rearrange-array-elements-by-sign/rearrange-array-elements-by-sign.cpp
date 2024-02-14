class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> p,n;
        for(auto i:nums){
            if(i<0) n.push(i);
            else p.push(i);
        }
        vector<int> res;
        int size = p.size();
        while(size--){
            res.push_back(p.front()); p.pop();
            res.push_back(n.front()); n.pop();
        }
        return res;
    }
};