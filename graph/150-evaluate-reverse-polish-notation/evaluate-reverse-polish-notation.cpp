class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> st;
      int res = 0;
      for(auto i:tokens){
          if(i=="+"||i=="-"||i=="/"||i=="*"){
              int b = st.top(); st.pop();
              int a = st.top(); st.pop();
              if(i=="+") st.push(b+a);
              else if(i=="-") st.push(a-b);
              else if(i=="*") st.push(a*b);
              else st.push(a/b);
          }else{
              st.push(stoi(i));
          }
      }
      return (st.empty())?-1:st.top();
    }
};