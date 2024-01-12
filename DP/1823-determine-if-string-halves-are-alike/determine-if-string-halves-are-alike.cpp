class Solution {
public:
    int check(string s){
        int cnt=0;
        for(auto i:s)
        switch(tolower(i)){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
             cnt++;
             break;
        }
        return cnt;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int s1 = check(s.substr(0,n/2));
        int s2 = check(s.substr(n/2,n/2));
        return s1==s2;
    }
};