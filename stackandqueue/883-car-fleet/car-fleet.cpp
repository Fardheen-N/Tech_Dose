class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n = speed.size();
        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        stack<float> st;
        for(int i=n-1;i>=0;i--){
            float time = ((target-cars[i].first)*1.0/cars[i].second);
            if(st.empty()||st.top()<time) st.push(time);
        }
        return st.size();
    }
};