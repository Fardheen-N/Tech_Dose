class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&temp[i]>=temp[st.top()]) st.pop();
            if(st.empty()) res[i]=0;
            else{
                res[i]=st.top()-i;
            }
            st.push(i);
        }
        return res;
    }
};