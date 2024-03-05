class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.size()-1;

        while(s[l]==s[r] && l<r){
            
            while(l+1<r && s[l+1]==s[r]){
                l++;
            }
            while(r-1>l && s[r-1]==s[l]){
                r--;
            }
            r--;l++;
        }
        return r-l+1;
    }
};