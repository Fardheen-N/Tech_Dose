class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int res=0;
        int left=0,right=0;
        while(right<s.size())
        {   char w=s[right];
            mp[w]++;
            while(mp[w]>1)
            {   char l=s[left];
                mp[l]--;
                left++;
            }
            res=max(res,right-left+1);
            right++;
        }  
        return res;
    }
};