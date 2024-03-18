class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        stack<int> st,ed;
        sort(points.begin(),points.end());
        int res = 0;
        for(auto i:points){
            if(ed.empty()){
                st.push(i[0]);
                ed.push(i[1]);
            }else if(ed.top()>=i[0]){
                st.push(i[0]);
                if(ed.top()>i[1]){
                    ed.pop();
                    ed.push(i[1]);
                }
            }else{
                res++;
                st.push(i[0]);
                ed.push(i[1]);
            }
        }
        return res+1;
    }
};