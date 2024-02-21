class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        vector<int> left(n),right(n+1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) left[i]=0;
            else left[i]=st.top()+1;
            
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) right[i]=n-1;
            else right[i]=st.top()-1;
            
            st.push(i);
        }
        for(int i=0;i<n;i++) cout<<left[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<right[i]<<" ";

        for(int i=0;i<n;i++){
            int l =left[i],r=right[i];
            int area = heights[i]*(r-l+1);
            res = max(res,area);
        }
        return res;
    }
};
