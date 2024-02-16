static int speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	return 0;
}();
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto i:arr){
            mp[i]++;
        }
        int res = 0;
        priority_queue<int,vector<int>,greater<int>> vals;
        for(auto i:mp){
            vals.push(i.second);
        }
        while(!vals.empty()){
            int val = vals.top(); vals.pop();
            cout<<val<<" ";
            k-=val;
            if(k<0) res++;
        }
        return res;
    }
};