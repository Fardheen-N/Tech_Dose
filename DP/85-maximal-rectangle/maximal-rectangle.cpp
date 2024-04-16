class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ht(n);
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    ht[j]++;
                }else{
                    ht[j]=0;
                }
            }
            res=max(findArea(ht,n),res);
        }
        return res;
    }
    int findArea(vector<int> &ht,int n){
        int res = 0;
        vector<int> left(n),right(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && ht[st.top()]>=ht[i]) st.pop();
            if(st.empty()) left[i]=-1;
            else left[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && ht[st.top()]>=ht[i]) st.pop();
            if(st.empty()) right[i]=n;
            else right[i]=st.top();
            st.push(i);
        }
        // for(auto i:ht) cout<<i<<" "; cout<<endl;
        // for(auto i:left) cout<<i<<" "; cout<<endl;
        // for(auto i:right) cout<<i<<" "; cout<<endl<<endl;

        for(int i=0;i<n;i++){
            
            res = max((right[i]-left[i]-1)*ht[i],res);
        }
        return res;
    }
};