class Solution {
private: 
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }            
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(dp[i][j]!=-1) continue;
                if(check(s, i, j)){
                    dp[i][j]=1;
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
}; 