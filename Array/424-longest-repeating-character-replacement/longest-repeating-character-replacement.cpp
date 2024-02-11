class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int l = 0,r =0;
        int res = 0,maxf = 0;
        while(r<s.size()){
            int size = r-l+1;
            mp[s[r]]++;
            maxf=max(maxf,mp[s[r]]);
            if(size-maxf>k){
                mp[s[l]]--;
                l++;
            }else{
                res = max(res,size);
            }
            r++;
        }
        return res;
    }
};