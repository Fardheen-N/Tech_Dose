class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int res = 0;
        for(auto i:s){
            if(i=='(') st.push(i);
            else if(i==')') st.pop();
            if(!st.empty() && res < st.size())res = st.size();
        }
        return res;
    }
};